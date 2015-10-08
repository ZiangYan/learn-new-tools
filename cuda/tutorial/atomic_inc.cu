#include <stdio.h>

const int ARRAY_SIZE = 10;
const int ARRAY_BYTES = ARRAY_SIZE * sizeof(int);
const int NUM_THREAD = 100000;
const int BLOCK_WIDTH = 100;

__global__ void naive_inc(int *g){
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    idx = idx % ARRAY_SIZE;
    g[idx] += 1;
}

__global__ void atomic_inc(int *g){
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    idx = idx % ARRAY_SIZE;
    atomicAdd(g + idx, 1);
}

int main(int argc, char **argv){
    int * d_arr;
    cudaMalloc((void **) &d_arr, ARRAY_BYTES);
    cudaMemset((void *) d_arr, 0, ARRAY_BYTES);
    //naive_inc<<<NUM_THREAD / BLOCK_WIDTH, BLOCK_WIDTH>>>(d_arr);
    atomic_inc<<<NUM_THREAD / BLOCK_WIDTH, BLOCK_WIDTH>>>(d_arr);
    int h_arr[ARRAY_SIZE];
    cudaMemcpy(h_arr, d_arr, ARRAY_BYTES, cudaMemcpyDeviceToHost);
    for (int i = 0; i < ARRAY_SIZE; ++i){
        printf("%d \t", h_arr[i]);
    }
    return 0;
}

