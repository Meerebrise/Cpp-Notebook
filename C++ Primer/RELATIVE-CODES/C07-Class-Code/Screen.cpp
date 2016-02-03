#include "stdafx.h"
#include "Screen.h"
#include <string>

//尽管some_member()是一个const函数，但依然可以改变mutable变量的值
void Screen::some_member() const
{
	++access_ctr;
}

