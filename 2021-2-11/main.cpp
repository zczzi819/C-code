#define _CRT_SECURE_NO_WARNINGS 
#include"test.h"
//如果是C语言不支持同名函数
//C++为了解决这个问题，支持同名函数，但是要求参数不同，或者个数不同或者类型不同
int add(int i, int j)
{
	return i + j;
}

double add(double i, double j)
{
	return i + j;
}

void f(int i, double d)
{

}

void f(double d, int i)
{

}

int main()
{
	 TestFunc(1,2,3);
	return 0;
}