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
	  Sales_data(const string &s) :bookNo(s) {};
	  Sales_data():bookNo(""),bookNu_sold(0),revenue(0.0) {}; //���캯����ʼֵ�б�
	  Sales_data(const string &s, unsigned n, double p) :bookNo(s), bookNu_sold(n), revenue(p*n) {};
	  Sales_data(std::istream &);

  private:
	  string bookNo;
	  unsigned bookNu_sold;
	  double revenue;
};

//Sales_data�ǳ�Ա��ɲ���
Sales_data add(const Sales_data&, const Sales_data&)
{

};

Sales_data::Sales_data(std::istream &)
{
}
