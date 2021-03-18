#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);
	void Print();

	Date(int year = 1900, int month = 1, int day = 1);

	void Add(int day);
	void Sub(int day);

	//void DateSubDate(Date d);

private:
	int _year;
	int _month;
	int _day;
};