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



