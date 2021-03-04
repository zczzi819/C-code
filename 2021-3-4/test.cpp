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
	Date& operator=(const Date& d)  //����������ֵ�����
	{
		if (this != &d)//ȡ��ַ
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
//һ������£���������س�ȫ�ֵĺ��������÷��ʳ�Ա����������ʵ��
//����һ������£�����ʵ�ֳ�Ա����
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
Stack st;//�����������������������

void f()
{
	static Date d;//����ʱֻ����һ�Σ����оֲ����ʣ���������������������
	Stack st;//����2�Σ����˺����͵�����������
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
//ȫ�ֶ��������˳���ڲ�ͬ�ļ����޷�ȷ��