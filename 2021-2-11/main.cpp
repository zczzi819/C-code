#define _CRT_SECURE_NO_WARNINGS 
#include"test.h"
//�����C���Բ�֧��ͬ������
//C++Ϊ�˽��������⣬֧��ͬ������������Ҫ�������ͬ�����߸�����ͬ�������Ͳ�ͬ
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