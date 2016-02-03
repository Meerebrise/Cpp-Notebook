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
	  
	  //��ʽ��ָ��Ϊ��������(ֻҪ�Ƕ��������ڲ��ĳ�Ա����)
	  char get() const 
	  {
		  return contents[cursor];
	  }

	  //����ڲ���ʾ��������������
	   char get() const
	  {
		  return contents[cursor];
	  }

	  //������move&&get����ֻ��������û�ж��壬����Ϊ����������
	  //��Ա����һ��Ҫ������������
	  //�����ⶨ�庯��ʱ����ָ��Ϊ��������
	  char get(pos r, pos c) const;
	  Screen &move(pos r, pos c);

	  void some_member() const;
 
   private:
	   pos cursor = 0;
	   pos height = 0, width = 0;
	   std::string contents;
	   mutable size_t access_ctr;

};

//������ⲿͨ��inline�ؼ������κ����Ķ���
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