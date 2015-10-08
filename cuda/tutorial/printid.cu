#include <stdio.h>

__global__ void printid(){
    int id = blockIdx.x;
    printf("I'm a thread in block %d!\n", id);
    __syncthreads();
    
}


int main(int argc, char **argv){
    printid<<<16, 1>>>();
    cudaDeviceSynchronize();
    printf("That's all!\n");
    return 0;
}
