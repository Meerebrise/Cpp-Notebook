#include "stdafx.h"
#include "Sales_data.h"
#include <iostream>
#include <string>

using namespace std;


class Sales_data {

  //������Ԫ����
//  friend 

  public:
	  Sales_data() = default;
	  Sales_data():bookNo(""),bookNu_sold(0),revenue(0.0) {}; //���캯����ʼֵ�б�


  private:
	  string bookNo;
	  unsigned bookNu_sold;
	  double revenue;
};

Sales_data add(const Sales_data&, const Sales_data&)
{

};