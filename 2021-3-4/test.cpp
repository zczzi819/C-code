#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		cout << "Date(int year = 1, int month = 1, int day = 1)" << endl;
		_year = year;
		_month = month;
		_day= day;
	}
	Date(Date&d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()
	{
		cout << "~Date()" << endl;
	}
	
	bool operator==(const Date& d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	//d0=d1=d2
	Date& operator=(const Date& d)  //存在连续复值的情况
	{
		if (this != &d)//取地址
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
//一般情况下，运算符重载成全局的函数，不好访问成员变量，不好实现
//所以一般情况下，都是实现成员函数
//bool operate < (const Date& d1, const Date& d2)
//{
//
//}
class Stack
{
public:
	Stack(int capacity = 4)
	{
		cout << "Stack(int capacity = 4)" << endl;
		_a = (int*)malloc(sizeof(int)*capacity);
		_capacity = capacity;
		_size = 0;
	}
	~Stack()
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_capacity = _size = 0;
	}
private:
	int* _a;
	int _size;
	int _capacity;

};
Stack st;//程序结束后，最后调用析构函数

void f()
{
	static Date d;//调用时只构造一次，带有局部性质，程序结束后调用析构函数
	Stack st;//构造2次，出了函数就调用析构函数
}
int main()
{
	Date d1(2021,3,2);
	//Date d1;
	//Date d2(2021,3,2);
	//Stack st;
	Date d2(d1);
	Date d3 = d1;
	Date d4;
	d4 = d1;
	//f();
	//f();
	d1 == d2;
	//d1.operator==(d2);//d1.operator==(&d1,d2);
	system("pause");
}
//全局对象的析构顺序在不同文件中无法确定