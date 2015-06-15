## 判断属于某几个之一：
if ok in ('y', 'ye', 'yes'):

## 为函数添加key-val类型参数
def parror(voltage, state='a stiff', action='voom'):

这样的函数可以直接用key-val风格的方式调用
parrot(voltage=5.0, action='kill')

## 参数打包
有* 和** 两种方式。
*和列表有关，在定义函数时，*把收进来的参数按位置排好
def sum(\*values): ###加\只是为了markdown显示方便，实际python代码不需要。
  s = 0;
  for v in values:
    s = s + v
  return s
在调用函数时，把参数解包
values = (1, 2)
s = sum(\*values)等价于s = sum(1, 2)

**和字典有关，在定义函数时，**把收进来的参数按照字典方式展开
def get_a(\*values, \*\*options):
  s = 0
  for v in values:
    s = s + v
  if "neg" in options:
    if options["net"]:
      s = -s
  return s
在调用函数时，把参数解包。

## list comprehension
map: 两个参数，第一个为函数，第二个为list
squares = map(lambda x: x ** 2, range(0, 10))
用list comprehension方式可以改写为
squares = [x ** 2 for x in range(10)]

list comprehension两个特点：
* 可以加条件
    [for in if]
* 可以连续叠加使用：
    vec = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    [num for elem in vec for num in elem]
* 可以多变量
    [(x, y) for x in range(0, 3) for y in range(0, 3) if x != y] 
* 可以嵌套
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    [[rows[i] for row in matrix] for i in range(4)]


## zip函数
zip用来把传入的各个list的第0、第1、……个元素分别打包。
zip(seq0, [seq1,...]) --> [(seq0[0], seq1[0], ...), (seq0[1], ...)...]
因此，zip可以用来转置矩阵
matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
matrix_transposed = map(list, zip(\*matrix))


## 

