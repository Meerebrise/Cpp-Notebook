#include "stdafx.h"
#include "Sales_data.h"
#include <iostream>
#include <string>



Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}


