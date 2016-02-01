#include "stdafx.h"
#include "Sales_data.h"
#include <iostream>
#include <string>

using namespace std;


class Sales_data {

  //声明友元函数
  //  friend 

  public:
	  Sales_data() = default;
	  Sales_data(const string &s) :bookNo(s) {};
	  Sales_data():bookNo(""),bookNu_sold(0),revenue(0.0) {}; //构造函数初始值列表
	  Sales_data(const string &s, unsigned n, double p) :bookNo(s), bookNu_sold(n), revenue(p*n) {};
	  Sales_data(std::istream &);

  private:
	  string bookNo;
	  unsigned bookNu_sold;
	  double revenue;
};

//Sales_data非成员组成部分
Sales_data add(const Sales_data&, const Sales_data&)
{

};

Sales_data::Sales_data(std::istream &)
{
}
