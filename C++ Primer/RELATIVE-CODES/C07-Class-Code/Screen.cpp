#include "stdafx.h"
#include "Screen.h"
#include <string>

//����some_member()��һ��const����������Ȼ���Ըı�mutable������ֵ
void Screen::some_member() const
{
	++access_ctr;
}

