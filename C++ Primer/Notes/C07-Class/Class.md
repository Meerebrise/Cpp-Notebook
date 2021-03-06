# 第七章 类

## 7.1 定义抽象数据类型

### 7.1.1 **成员函数相关**

*   **定义**：为类的一部分的函数，有时也被称为方法(method)。

* 成员函数的**声明必须在类的内部**，而定义可以在类的内部或者外部,**定义**在类内部的函数是隐式的inline函数。

* 点运算符符用于获取类对象的成员:比如：```total.isbn()```来访问total对象的isbn成员。

* total.isbn() (isbn为成员函数)：成员函数通过一个名为**this**的额外参数来访问调用它的对象。
当调用成员函数时，用请求该函数的对象的地址来初始化参数**this**。
在这里相当于：``` Sales_data::isbn(&total) ``` 。

* 在成员函数内部，可以直接使用调用该函数的对象的成员而无需成员访问符。任何对类成员的直接访问都被看作this的隐式引用。就像书写了```this->bookNo```。

* **inline**和**constexpr**以及**inline成员函数**应该定义在相应的头文件中。 

### 7.1.2 **常量成员函数(const member function)**

* ``this``指针用来保存调用该函数的对象的地址

* 成员函数后面紧跟的"const"用于修改隐式this指针的类型。

* this是一个常量指针(**const pointer**)，也即无法改变this中保存的地址。 默认情况下指向类类型为**非常量版本的常量指针**。在本例中为(``` Sales_data *const ``` )。

* **常量对象，以及常量对象引用或者指针都只能调用常量成员函数**。

* `this这里非指向常量的指针，所以不能指向常量。`（即当调用对象为常量对象时，this不能绑定上去）

### 7.1.3 类作用域和成员函数

* 编译器分两步处理类:首先编译成员的声明，然后才轮到成员函数。

* 非成员函数的声明和类在同一个头文件中。

### 7.1.4 在类的外部定义成员函数

* 类外部定义的成员函数必须包含它**所属的类名**。

### 7.1.5 构造函数

* ```A() = default;```创建默认构造函数。

* 任务:初始化类对象的数据成员，无论何时只要类的对象被创建，就会执行构造函数。

* 构造函数不能被声明成**const**。当创建一个类的const对象时，直到构造函数完成初始化过程，对象才能真正取得**"常量"**属性。

* 默认构造函数执行过程：

> 如果存在类内初始值，则用它来初始成员

> 否则，默认初始化。

* C++ 11规定，可以为数据成员提供一个类内初始值。

### 7.1.6 构造函数初始值列表

* 冒号以及冒号和花括号之间的代码称为构造函数初始值列表，用来为新创建的对象的一个或几个数据成员赋初值。

* 当某个数据成员被构造函数初始值列表忽略时，它将以与默认构造函数相同的方式隐式初始化。

* 和其他成员函数一样，当我们在类的外部定义构造函数时，需要指明该构造函数是哪个类的成员。

## 7.2 访问控制与封装

### 7.2.1 访问控制与封装

* 定义在private说明符之后的成员可以被类的成员函数访问，非类的成员函数不能访问，要借助友元这个概念。

* struct与class的默认访问权限不一样。

* 类可以在第一个访问说明符之前定义成员，这种成员的访问权限依赖于类定义的方式

> struct：第一个说明符之前的成员为public

> class: private

* 希望类的所有成员为public，用struct。

* 希望类的成员为private则用private。

### 7.2.2 友元

* 类允许其他类或者函数访问该类的私有成员，即令他们成为它的友元(friend)。另一个函数成为它的友元，只需增加一条以**friend**关键字开始的函数声明语句即可。

* **友元声明只能出现在类定义的内部，具体位置不限**。

## 7.3 类的其他特性

### 7.3.1 类成员再探

* **定义(非声明)**在类内的成员函数都自动为inline函数，类的外部用`inline`关键字修饰函数的**定义**可以达到相同效果。

* 可变数据成员(mutable data member)即使在const函数中依然可以被改变。

### 7.3.3 类类型

* 即使两个类的成员列表完全一致，它们都是不同的类型。

        struct First{
             int memi;
             int getMem();
        };
 
        struct Second{
             int memi;
             int getMem();
        };
上面两个类的类型不一样，虽然他们的成员列表"完全一样"。

* 不完全类型：```class Screen;```称为前向声明，这时Screen是一个不完全类型。

* 有限情况下使用不完全类型：
    * 可以定向指向这种类型的指针或者引用
    * 作为参数或者返回类型的函数
    
* 创建某个类的对象时，**该类必须先被定义过**，光有声明并没有用。


### 7.3.4 友元再谈

* 令类A为类B的友元类（在B.h中） 

    ```friend Class A;```

* 友元不具有传递性

* 如果一个类A成为了类B的友元类，则类**A的成员函数**可以访问类B所有成员(包括私有成员)。

* 声明某个成员函数为友元
   
    ```friend void Window_mgr::clear(ScreenIndex i);```

* 一个const成员函数如果以引用的形式返回*this,那么它的返回值类型将是常量引用。

 
## 7.4 类的作用域

### 7.4.1 名字查找和作用域

* 编译器处理完类中的全部声明后才会处理成员函数的定义

* 类型名重定义如下，在某些编译器中属于错误**(重定义Money类型)**

        typedef double Money;
        class Account
        {
          private:
	        typedef double Money;
        };

* 类型名的定义最好放在类的开头处

### 7.4.2 成员定义中的普通块作用域的名字查找

      int height; //定义在类外
      class Screen{
      public:
          typedef std::string::size_type pos;
          void dummy_fcn(pos height) {
             cursor = width * height;
          }
      private:
          pos cursor = 0;
          pos height = 0,width = 0;
      };

      此时参数height隐藏了同名成员

如果要访问成员height(Two Methods)。
    
    void Screen::dummy_fcn(pos height) {
        //Method 1  this
        cursor = width*this->height;
        
        //Method 2  Screen::
        cursor = width*Screen::height;
    }
     
如果要访问类外的全局height，通过**域作用符**访问。

     void Screen::dummy_fcn(pos height) {
         
          cursor = width * ::height;
     }


* 除了类定义之前的全局声明，还要包括成员函数**(类外的)**定义之前的全局声明。
 
## 7.5 构造函数再探

### 7.5.1 构造函数初始值列表

* 必须通过构造函数初始值列表提供初始值的成员：const、引用、为提供默认构造函数的类类型

* 成员将在构造函数初始化之前默认初始化，当没有通过构造函数初始值列
表初始化时。

### 7.5.3 默认构造函数的作用

* 对象被默认初始化或值初始化 -> 自动执行默认构造函数

### 7.5.4 
 
* 只接受**一个参数**的构造函数，实际上定义了转换为此类类型的隐式转换机制。

* 单实参构造函数：构造函数的参数类型 -> 类类型

* 关键字**explicit**：用于抑制构造函数定义的隐式转换。只能出现在类内声明中，不应重复出现在类外定义。

* **explicit**构造函数只能用于直接初始化，不能用于拷贝形式。

### 7.5.5 聚合类(aggregate class)

* 可以直接访问成员的类，没有特殊的初始化语法

* 当类满足如下条件时，即为聚合的：

>* 所有成员都是public
>* 没有定义任何构造函数
>* 没有类内初始值
>* 没有基类，也没用virtual函数

* 聚合类如下

        struct Data{
           int ival;
           string s;
        };

* 初始化聚合类

    * 用花括号形式
    * 初始化时的初始顺序严格要求
    
     ```Data val1 = {0,"Steve"};```


## 7.6 类的静态成员

* 静态成员通过关键字**static**声明。

* 类的静态成员存在于任何对象之外，对象也不包含任何与静态数据成员有关的数据。

* 静态成员函数不与任何对象绑定在一起，它们不包含this指针，同时静态成员函数也不能声明为const的。
  
* 可以通过类的对象、引用或者指针来访问。

* 成员函数不用通过作用许运算符就能直接使用静态成员。

* 在类外定义静态函数时，**static**不需要重复。

* 必须在类的外部定义和初始化类的静态成员。

* 当静态成员是字面值常量类型时，初始值必须是常量表达式，这时候可以对类的静态成员进行类内初始化。

* 即使一个常量静态数据成员被初始化了，最好也要在类外**重新定义**一下。