# 把命令返回结果存入变量

    a=$(id -u)
    a=$(ls)

# 分支语句

    if [ -d note.md ]; then
        echo "There is a note.md"
    else
        echo "There isn't a note.md"
    fi

在[和条件开始之间必须有一个空格，在]和条件结束之间也必须有一个空格

# 比较两变量是否相等

    if [ $(id -u) = "0" ]; then
        echo "You are super user"
    else
        echo "You are not super user"
    fi

# 比较数字是否相等

    if [ $a -eq $b ]; then

# 表达式求值

    seconds=0
    hours=$((seconds/3600))

用两层小括号把表达式括起来，就将进行表达式求值。注意seconds前面不用加$符号

# [[和[
[[是[的高级版，主要在处理字符串和文件做了很多增强，bash,zsh等支持[[。最明显的好处是可以用通配符和正则表达式：

    [[ $name = a* ]] || echo "name does not start with an 'a'
    [[ $(date) =~ ^Fri\ ...\ 13]] && echo "It's Friday the 13th!"

注意，|| 后面的语句只有当前面的语句为假才执行，而&& 后面的语句只有当前面的语句为真才执行。

# case 语句
基本语法格式为

    case $var in 
        pattern1 ) do something
            ;;
        pattern2 ) do something
            ;;
        ...
        * ) do something
    esac

其中pattern可以是具体的值，例如"0"，也可以是通配符，例如[a-z]，还可以用或符号|连接，例如[a-z] | [A-Z]。;;是case所特有的，用在每种情况的后边，相当于C中的break。

# find 命令
可以带的参数有：

    -maxdepth
    -mindepth
    -name 可用通配符：-name *.jpeg
    -type 指定类型：-type d只寻找目录

# 命令行参数
对于如下命令：

    some_command arg1 arg2 args

有：
    
    $0：some_command
    $1: arg1
    $2: arg2
    $3: arg3

# grep
可以加 -A2 把目标连同后两行一并输出,加 -B5 把目标连同前5行一并输出.


