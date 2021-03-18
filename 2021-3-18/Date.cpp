#include "Date.h"

Date::Date(int year, int month, int day)
{
	if (year >= 0 &&
		month > 0 && month < 13 &&
		day > 0 && day < GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" << endl;
	}
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

void Date::Add(int day)
{

}

void Date::Sub(int day)
{

}

//void DateSubDate(Date d)
//{
//
//}