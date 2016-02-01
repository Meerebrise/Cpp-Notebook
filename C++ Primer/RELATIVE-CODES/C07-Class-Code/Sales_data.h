#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

class Sales_data
{
	//友元函数声明
	friend Sales_data add(const Sales_data&,const Sales_data&);
	friend std::ostream &print(std::ostream&,const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);

	//构造器
    public:
		Sales_data() :bookNu_sold(0), revenue(0.0) {};
		Sales_data(const std::string &s):bookNo(s), bookNu_sold(0), revenue(0.0) {};
		Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), bookNu_sold(n), revenue(n*p) {};
		Sales_data(std::istream &);

    private:
		std::string bookNo;
		unsigned bookNu_sold;
		double revenue;
};



#endif