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
