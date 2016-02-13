#include "Sales_data.h"
#include <iostream>

using namespace::std;

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

Sales_data&
Sales_data::combine(const Sales_data &rhs)
{
	unit_sold += rhs.unit_sold;
	revenue += rhs.revenue;
	return *this;
}

double
Sales_data::avg_price() const
{
	if (unit_sold)
		return revenue / unit_sold;
	else
		return 0;
}

istream&
read(istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.unit_sold >> price;
	item.revenue = price*item.unit_sold;
	return is;
}

ostream&
print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.unit_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data
add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}