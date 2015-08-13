## 安装
用下列命令可快速安装除CUDA/cnDNN以外**所有**依赖库：

    sudo apt-get install libatlas-dev libatlas-base-dev libboost-dev libboost-all-dev libboost-system-dev libboost-thread-dev libboost-python-dev libopencv-dev libprotobuf-dev protobuf-compiler libhdf5-dev libleveldb-dev liblmdb-dev libsnappy-dev libpython-dev libpython2.7 automake cmake python-pip python-dev
    export CAFFE_ROOT=/path/to/your/caffe
    sudo pip install -r $CAFFE_ROOT/python/requirements.txt

用下列命令配置编译：

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

如果缺少某一部分，可能是配置不正确，建议纠正后再编译。特别是，**如果缺少Python或者Matlab这两个标题，则不会编译对应接口**，这点一定要注意，不要问我怎么知道的TAT。

cmake正确后，就可以进行编译：

    make -j7

-j后面的数字代表并行编译的核数目，建议设置为你的CPU实际并行核数目-1。CPU并行核数目可在terminal中用nproc查看。

编译完成后，可以在```PATH```环境变量中添加```$CAFFE_ROOT/build/tools```以便使用命令行接口。此外，如果要使用Python接口，还需在环境变量```PYTHONPATH```中加入```$CAFFE_ROOT/python```。

### Python接口
在用cmake配置安装过程时，如果python的包不够全会发生不自动编译pycaffe模块的现象，但并不会有任何提示。这样，在import caffe时会发生no module named \_caffe的错误。解决方法是在CAFFE\_ROOT下sudo pip install -r ./python/requirements.txt，然后再sudo apt-get install libboost-python-dev，然后删掉build文件夹，重新cmake，重新make。 

### Matlab接口
* 在用cmake配置安装过程时，如果matlab是采用在PATH中添加/usr/local/MATLAB/R20xxx/bin这种方式，则会出现找不到matlab的情况。这一方案很不规范，不应当在PATH中直接加软件可执行文件夹，而应当在/usr/bin下建立软链。
* 如果gcc版本不正确，会无法mex。例如Matlab R2014b要求用gcc4.7.x，但笔者写此文档时Ubuntu15.04自带gcc4.9.2，因此需要安装gcc4.7和g++4.7，并设置系统默认gcc&&g++版本为4.7
* 在某些情况下mex会试图链接lpython2，而我们安装的往往是lpython2.7，因此需要创建符号链接。先找到libpython2.7.so，然后链接到/usr/lib下。在笔者的计算机上，命令如下：

    sudo ln -s /usr/lib/x86\_64-linux-gnu/libpython2.7.so /usr/lib/libpython2.so

然后重新make即可。


# loss很大的可能原因

* ```base_lr```设置过大
* 不恰当的```scale```也将导致学习速率过大.需要注意的是,采用```ImageDataLayer```时,要注意```transform_param```和```image_data_param```中要**同时**设置```scale```的值.**仅在```image_data_param```或者```transform_param```中设置是无效的.**这可能是caffe的一个bug.

