# Google Style Guide

## C++ 特性

* 函数的输入参数可以是值或者const引用，输出参数是指针。输入参数也可以是const指针，但不能是非const的引用，除非另有处理，例如```swap()```
* 不用C风格的类型转换，用```static_cast```/```const_cast```等 

## 命名约定

### 普通变量
* ```num_errors```
* ```num_dns_connections```

### 类名
* ```class MyExcitingClass { ...```
* ```class UrlTableTester { ... ```

### 类成员变量
* 名字后加下划线 
    
    class TableInfo {
        ...
      private:
        string name_;
        static Pool<TableInfo*> pool_
    };

### 类成员函数
* 常规函数每个单词首字母都大写```MyExcitingFunction()```
* 取值和设值函数和变量名匹配

    class MyClass {
        public:
            int num_entries() const { return num_entries_;}
            void set_num_entries(int num_entries) { num_entries_ = num_entries;}
        private:
            int num_entries_;
    }

## 缩进

### if-else 空格
* ```if```和圆括号之间，圆括号和大括号之间都要加空格。圆括号内部可加可不加，我不加
    
    if (condition) {
        // do something
    }

### 预处理指令
* 带有#的预处理指令**不要缩进**，从行首开始，即使位于缩进的代码块中




