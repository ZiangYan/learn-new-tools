#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cuda_runtime.h>
#include "cublas_v2.h"
#define IDX2C(i ,j , ld) (((j)*(ld))+(i))
#define n 5 // size of matrix A (i.e., number of column)
int main (void) {
    cudaError_t cudaStat ; // cudaMalloc status
    cublasStatus_t stat ; // CUBLAS functions status
    cublasHandle_t handle ; // CUBLAS context
    int i, j; // i-row index , j-column index
    float *A; // A - n*n matrix on the host
    float *L; // L - n*n matrix on the host

    A = (float*) malloc(n * n * sizeof(float)); // host mem. alloc for A
    L = (float*) malloc(n * n * sizeof(float)); // host mem. alloc for L
    // define a positive definite matrix A
    A[0]  = 1; A[1]  = 2;  A[2]  = 4;   A[3]  = 3;  A[4]  = 2;
    A[5]  = 2; A[6]  = 13; A[7]  = 17;  A[8]  = 21; A[9]  = 10;
    A[10] = 4; A[11] = 17; A[12] = 29;  A[13] = 33; A[14] = 16;
    A[15] = 3; A[16] = 21; A[17] = 33;  A[18] = 68; A[19] = 24;
    A[20] = 2; A[21] = 10; A[22] = 16;  A[23] = 24; A[24] = 11;
    printf("Original matrix A:\n");
    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j){
            printf(" %4.0f", A[IDX2C(i, j, n)]);
        }
        printf("\n");
    }
    float *d_L; // d_L - L on the device
    float sqrta11 = sqrt(A[0]);
    cudaStat = cudaMalloc((void **)&d_L, n * n * sizeof(float)); 
    stat = cublasCreate(&handle);
    stat = cublasSetMatrix(n, n, sizeof(*L), A, n, d_L, n); // initialize d_L from A

    // compute first column
    stat = cublasSscal(handle, n, &sqrta11, d_L, 1); 

    // compute second to last column
    float t1;
    float alpha = -1.0f;
    float beta = 1.0f;
    for (j = 1; j < n; ++j){
        stat = cublasSgemv(
                handle, 
                CUBLAS_OP_N, 
                n - j,   // number of rows of matrix
                j,       // number of cols of matrix 
                &alpha,  // alpha
                d_L + j, // pointer to matrix
                n,       // leading dimension of matrix 
                d_L + j, // pointer to x
                n,       // incx
                &beta,   // beta
                d_L + j * n + j, // pointer to y
                1);      // incy
        stat = cublasGetVector(1, sizeof(float), d_L + j * n + j, 1, &t1, 1);
        t1 = 1 / sqrt(t1);
        stat = cublasSscal(handle, n - j, &t1, d_L + j * n + j, 1);
    }

    // fetch result from GPU memory
    stat = cublasGetMatrix(n, n, sizeof(float), d_L, n, L, n);

    printf("After cholesky decomposition:\n");
    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j){
            printf(" %4.0f", L[IDX2C(i, j, n)]);
        }
        printf("\n");
    }

    cudaFree(d_L); 
    cublasDestroy(handle); 
    free(A); 
    free(L); 
    return EXIT_SUCCESS ;
}
