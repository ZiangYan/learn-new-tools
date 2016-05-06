# 更改ipython notebook默认字体的教程

ipython notebook默认的字体是非等宽字体，小写的字母L会特别瘦，这种字体无法使代码对齐，从而属于码农最讨厌的几件事情之一。经过一些折腾，找到了修改该特性的方法。在ipython notebook中，渲染到网页上的样式是由一系列CSS文件控制的，这些文件从属于jupyter这一python包。因此我们只要修改对应的CSS即可

1. 在终端中查看jupyter配置目录的路径

        jupyter --config-dir

在笔者的计算机上，jupyter配置目录位于`/home/yanziang/.jupyter`

2. 创建自定义CSS目录

        mkdir /home/yanziang/.jupyter/custom

3. 下载[custom.css](custom.css)，并将其放入刚创建的CSS目录中。该文件中有说明网页上各部分对应哪段CSS
4. 重启ipython notebook
