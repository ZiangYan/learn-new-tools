─────────────────────────────────────────────────────────────────────────────
    var fs = require('fs')
    var path = require('path')
    
    fs.readdir(process.argv[2], function (err, list) {
      list.forEach(function (file) {
        if (path.extname(file) === '.' + process.argv[3])
          console.log(file)
      })
    })

─────────────────────────────────────────────────────────────────────────────
### 匿名函数
function (err, list)为匿名函数.这种用法解决了不会起名字的烦恼2333

### forEach
list.forEach用法,定义一个匿名函数,接受每个元素,太爽了!!

###  list.filter
在filter时会创建一个list副本,在副本上进行filter.因此执行这一操作并不会改变list.
需要改变list的话,要用list = list.filter(function (element){/*...*/})

### console.log
在callback只做打印时,可以把console.log直接填到callback的位置上,不需要构造匿名函数.例如:
response.on('data', console.log);
而不用
response.on('data', function (data) { console.log(data);});

