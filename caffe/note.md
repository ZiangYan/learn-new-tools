## 安装
用下列命令可快速安装除CUDA/cnDNN以外**所有**依赖库：

    sudo apt-get install libatlas-dev libatlas-base-dev libboost-dev libboost-all-dev libboost-system-dev libboost-thread-dev libboost-python-dev libopencv-dev libprotobuf-dev protobuf-compiler libhdf5-dev libleveldb-dev liblmdb-dev libsnappy-dev libpython-dev libpython2.7 automake cmake python-pip python-dev libgflags-dev libgoogle-glog-dev gfortran cython3
    export CAFFE_ROOT=/path/to/your/caffe

由于pip设计不甚完善，在同时安装互相依赖的多个python包时处理不好，所以建议裸机在装python包时采用先安装依赖浅的包，再安装依赖深的包：

    sudo pip install numpy
    sudo pip install scipy
    sudo pip install matplotlib
    sudo pip install -r $CAFFE_ROOT/python/requirements.txt

所以依赖库以及python依赖包安装完成后，用下列命令配置编译：

    cd $CAFFE_ROOT
    mkdir build && cd build && cmake ..

cmake最后输出含有的**标题**应该有：

* General
* Dependencies
* NVIDIA CUDA
* Python
* Matlab
* Documentation
* Install

如果缺少某一部分，可能是配置不正确，建议纠正后再编译。特别是，**如果缺少Python或者Matlab这两个标题，则不会编译对应接口**，这点一定要注意

cmake正确后，就可以进行编译：

    make -j7

-j后面的数字代表并行编译的核数目，建议设置为你的CPU实际并行核数目-1。CPU并行核数目可在命令行中用```nproc```命令查看。

编译完成后，为方便调用命令行接口和python接口，可以按如下方式添加环境变量，根据喜欢用的shell的不同，写到```~/.bashrc```或```~/.zshrc```中：

    export CAFFE_ROOT=/path/to/your/caffe
    export PATH=$PATH:$CAFFE_ROOT/build/tools
    export PYTHONPATH=$PYTHONPATH:$CAFFE_ROOT/python
    


### Python接口
在用cmake配置安装过程时，如果python的包不够全会发生不自动编译pycaffe模块的现象，但并不会有任何提示。这样，在试图```import caffe```时会发生```no module named _caffe```的错误。解决方法是按照本教程前文所讲的方式安装python软件包，然后删掉```build```文件夹，重新```cmake```，重新```make```。 

### Matlab接口
* 在用cmake配置安装过程时，如果matlab是采用在```PATH```中添加```/usr/local/MATLAB/R20xxx/bin```这种方式，则会出现找不到matlab的情况。这一方案很不规范，不应当在```PATH```中直接加软件可执行文件夹，而应当在```/usr/bin```下建立软链。
* 如果gcc版本不正确，会无法mex。例如Matlab R2014b要求用gcc4.7.x，但笔者写此文档时Ubuntu15.04自带gcc4.9.2，因此需要安装gcc4.7和g++4.7，并设置系统默认gcc&&g++版本为4.7
* 在某些情况下mex会试图链接lpython2，而我们安装的往往是lpython2.7，因此需要创建符号链接。先找到libpython2.7.so，然后链接到```/usr/lib```下。在笔者的计算机上，命令如下：

        sudo ln -s /usr/lib/x86_64-linux-gnu/libpython2.7.so /usr/lib/libpython2.so

然后重新```make```即可。


# loss维持在83左右的可能原因

* ```base_lr```设置过大，导致发散
* 不恰当的输入图片```scale```也等效于学习速率过大
* 有些层的初始化不恰当，导致对于大量样本以极高概率给出错误判断，从而出现```NaN```，造成数值上的问题。这种情况容易发生在从别人训练好的网络在自己的数据集上finetune时，因为此时往往改掉了输出层的输出节点个数，如果这层全连接还按照别人网络的噪声水平随机初始化，往往会造成这个问题。建议采用msra或者xavier方式来初始化
