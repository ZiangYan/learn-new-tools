
# CUDA基础
## 获取索引
每个kernel函数中都可以直接获取如下四个变量:
* gridDim.{xyz}:全局grid在xyz方向上分别有几个block
* blockIdx.{xyz}:当前block在全局grid中的索引
* blockDim.{xyz}:一个block在xyz方向上分别有几个thread
* threadIdx.{xyz}:当前thread在当前block中的索引

## communication patterns
* map
* gather
* scatter
* stencil
* transpose

## CUDA 保证与不保证
CUDA保证如下内容:
* 同一block中的所有thread都在同一个Streaming Multiprocessor(SM)中,并且同时开始运行
* 所有block都将在下一kernel开始执行前结束

CUDA不保证如下内容:
* 一个SM上运行的block数量

## Barrier
Barrier提供block-level的同步.在kernel函数中用```__syncthreads()```添加barrier.这将导致同一个block中的所有thread在完成barrier前所有内容前互相等待,直到同一block中的所有thread都完成barrier前所有内容为止.

## Memory model
GPU的内存分三级:global/shared/local.所有block中所有thread都能访问的,是global;同一block中各个thread能访问的,是shared;只有thread自己能访问的,是local.

访问速度:local > shared >> global >> cpu memory

在kernel函数中,用```__shared__```指定shared memory.

# 基本并行算法
## scan
* Steele scan: work nlog(n), step log(n)
* Blelloch scan: work n, step 2log(n)
当GPU work 效率高,选Steele, 当GPU step效率高,选Blelloch.




# 坑
## 图片x轴与y轴
OpenCV读入的图片按照H*W*C,按行优先顺序存储.假如一张灰度图宽500,高300,我们设定block和grid都是二维,每个block中有16*16个thread.那么,水平方向需要32个block,竖直方向需要19个block.在每个thread中,我们在开头应当加入类似如下代码来获取在图片中的位置:

    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row >= numRows || col >= numCols){
        return;
    }
    int index = row * numCols + col;
    unsigned char pixel = image[index];
    
看起来一切都很好.在启动kernel时,显然block的规模是dim3(16, 16, 1).那么,grid的规模是多少呢?是dim3(32, 19, 1)还是dim3(19, 32, 1)?正确答案应当是dim3(32, 19, 1).

2015年10月8日,在grid规模的问题上首次被坑.如果以后再被坑,请增加如下计数器的值:

    被坑的总时间=2h