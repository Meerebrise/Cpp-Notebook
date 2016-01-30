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
	  Sales_data():bookNo(""),bookNu_sold(0),revenue(0.0) {}; //构造函数初始值列表


  private:
	  string bookNo;
	  unsigned bookNu_sold;
	  double revenue;
};

Sales_data add(const Sales_data&, const Sales_data&)
{

};