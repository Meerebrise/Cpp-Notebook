# 第六章 函数

## 6.1 函数基础

#### 6.1.1 局部对象

* **局部变量：** 形参和函数体内定义的局部变量

* 自动对象： 我们把只存在于块执行期间的对象称为**自动对象**(automatic object)，也就是局部变量对应的对象。

* 局部静态对象:将局部变量定义为**static**类型。

> 在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止才被销毁，在此期间，即使对象所在的函数结束执行也不会对它产生影响。该局部变量的生命周期贯穿函数调用及之后的时间。

* 内置类型的未初始化局部变量将产生未定义的值。

* 当局部静态变量的值没有显示初始化时，讲执行值初始化。(p88)

## 6.5 特殊用途语言特性

### 6.5.2 内联函数

* 内联函数只是发向编译器的一个请求，编译器可以忽略这个请求。

* 内联函数定义放在头文件内。 

### 6.5.3 constexpr函数

* constexpr函数的返回值和参数类型都必须为字面值类型