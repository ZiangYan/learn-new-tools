# theano学习笔记
本笔记是学习[theano官网教程](http://deeplearning.net/software/theano/tutorial/)所记录。
## 数据类型
|theano中名称|常用名称|
|:---------:|:-----:|
|b|byte|
|w|int16|
|i|int32|
|I|int64|
|f|float32|
|d|float64(double)|
|c|complex64|
|z|complex128|

## pretty-print函数
假设```z=x+y```，那么
 
    from theano import pp
    print pp(z)
    
将输出

    (x + y)
    
## 调试经验
* 用```THEANO_FLAGS=mode=FAST_COMPILE ./run.py```可以使theano基本只用python的实现而不编译，可以在调试时快速测试模型对不对。等到模型调试正确了，运行时再改回```THEANO_FLAGS=mode=FAST_RUN ./run.py```即可
