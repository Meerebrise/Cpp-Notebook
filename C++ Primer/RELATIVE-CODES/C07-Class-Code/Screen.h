#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>

class Screen {

   public:
	  //typedef std::string::size_type pos;
	  using pos = std::string::size_type;
	  Screen() = default;
	  Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
	  
	  //隐式地指定为内联函数(只要是定义在类内部的成员函数)
	  char get() const 
	  {
		  return contents[cursor];
	  }

	  //类的内部显示地声明成内联的
	   char get() const
	  {
		  return contents[cursor];
	  }

	  //在这里move&&get函数只有声明，没有定义，所以为非内联函数
	  //成员函数一定要在类内先声明
	  //在类外定义函数时可以指定为内联函数
	  char get(pos r, pos c) const;
	  Screen &move(pos r, pos c);

	  void some_member() const;
 
   private:
	   pos cursor = 0;
	   pos height = 0, width = 0;
	   std::string contents;
	   mutable size_t access_ctr;

};

//在类的外部通过inline关键字修饰函数的定义
 inline char Screen::get(pos r, pos c) const
{
	pos row = r*width;
	return contents[row + c];
}

 Screen &Screen::move(pos r, pos c)
{
	pos row = r*width;
	cursor = row + c;
	return *this;
}

#endif