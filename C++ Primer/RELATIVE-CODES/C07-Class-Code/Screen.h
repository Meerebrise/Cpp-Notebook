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
	  //隐式地指定为内联函数
	  char get() const 
	  {
		  return contents[cursor];
	  }

	  inline char get() const
	  {
		  return contents[cursor];
	  }

	  Screen &move(pos r, pos c);

	  const int ci = 1024;
	  const int &r = ci;

   private:
	   pos cursor = 0;
	   pos height = 0, width = 0;
	   std::string contents;

};


#endif