# 10 minutes to pandas
pd.Series.dtype可以查看数据类型

dates = pd.date\_range('20130101', periods=6)可以生成DatetimeIndex对象，用来做DataFrame的index。
df = pd.DataFrame(np.random.randn(6, 4), index=dates, columns=list('abcd'))

df.head(n)和df.tail(n)可以查看头n个和尾巴n个数据

df.index可以看DataFrame的index，df.columns可以看columns，df.values返回numpy存储的value

df.describe返回每一列的计数，均值，最大值，最小值，25/50/75分位数等

df.T将df进行转置，index变columns，columns变index

## indexing and selecting data
最简单的，可以用方括号直接索引。这个和python的方括号一样，含前不含后

loc是最常用的selection by label方法。处理Series对象时，loc的参数被理解为是index的值，而不是位置
loc和python的方括号不同的是，loc['a':'b']会返回index为'a'和'b'对应的数据，含前也含后
loc处理DataFrame时，先index，后columns。全部选中可以用冒号。当选中一行或一列时，返回Series。当选中一块时，返回DataFrame。神奇的是，对于日期做的index，loc可以用类似这种语法df.loc['2013-01-01':'2013-01-04', :]
当loc处理DataFrame，并且只被传入了一个参数时，所有columns是默认全部被选中的

iloc是最常用的selection by position方法。传入的参数被认为是位置，从0开始，含前不含后。

## split-apply-combine
pandas有一个常见的范式，就是按照某个原则将数据切分成若干组，然后对于每一组独立地进行操作，最后将结果组合

grouped = df.groupby('A')将按照df的'A'这个columns的不同取值，来group。执行这一行的时候不会发生实际的group

grouped.first(), grouped.last(), grouped.groups, grouped.get\_group()分别用来取出第一组，最后一组，查看所有组，取出任意一组

如果按照'A'进行group了，想看每个group的'C'那一列的内容，一般做法是
grouped = df.groupby('A')
grouped['C']
pandas提供了语法糖，可以df['C'].groupby(df['A'])

grouped可以被遍历

    for name, group in grouped:
        print name
        print group

grouped.agg用来把每个组的所有值映射为一个值
grouped.transform用来把每个组的值进行变换
grouped.filter用来把不想要的组过滤掉
grouped.apply啥都能干，但是返回的形状情况比较多，有讲究
