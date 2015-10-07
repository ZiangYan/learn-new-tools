#include <stdio.h>

__global__ void cube(float *d_in, float *d_out){
    int idx = threadIdx.x;
    float data = d_in[idx];
    d_out[idx] = data * data * data;
}


int main(int argc, char ** argv){
    const int ARRAY_SIZE = 96;
    const int ARRAY_BYTES = ARRAY_SIZE * sizeof(float);
    float h_in[ARRAY_SIZE];
    float h_out[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i){
        h_in[i] = i;
    }
    float *d_in;
    float *d_out;
    cudaMalloc((void **) &d_in, ARRAY_BYTES);
    cudaMalloc((void **) &d_out, ARRAY_BYTES);
    cudaMemcpy(d_in, h_in, ARRAY_BYTES, cudaMemcpyHostToDevice);
    cube<<<1, ARRAY_SIZE>>>(d_in, d_out);
    cudaMemcpy(h_out, d_out, ARRAY_BYTES, cudaMemcpyDeviceToHost);
    for (int i = 0; i < ARRAY_SIZE; ++i){
        printf("%f \t", h_out[i]);
        if (i % 4 == 0){
            printf("\n");
        }
    }
    return 0;
}

