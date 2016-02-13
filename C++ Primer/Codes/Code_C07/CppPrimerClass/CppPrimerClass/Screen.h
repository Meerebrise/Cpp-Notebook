#pragma once

#include <string>
#include <vector>
#include <iostream>

class Screen
{
	friend class Window_mgr;
public:
	//typedef std::string::size_type pos;
	using pos = std::string::size_type;

	Screen() = default;
	Screen() : cursor(0), height(0), width(0) { }
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
	Screen(pos ht = 0, pos wd = 0) : cursor(0), height(ht), width(wd), contents(ht * wd, ' ') { }
	char get() const { return contents[cursor]; } //定义在类内的函数隐式为inline函数
	inline char get(pos ht, pos wd) const;
	Screen &clear(char = bkground);
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}

	/*
	*  基础const的重载
	*  返回的类型是常量引用
	*/
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}

private:
	static const char bkground = ' ';
	void do_display(std::ostream &os) const { os << contents; }
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

};

inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width; // compute the row location
	cursor = row + c;    // move cursor to the column within that row
	return *this;        // return this object as an lvalue
}

inline
Screen& Screen::set(char c)
{
	contents[cursor] = c; // set the new value at the current cursor location
	return *this;
}

inline
char Screen::get(pos r, pos c) const
{
	pos row = r * width;      // compute row location
	return contents[row + c]; // return character at the given column
}

inline
Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;  // set specified location to given value
	return *this;
}