#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
void fun2()
{
	printf("hello\n");
}
void fun1()
{
	fun2();
}

void fun()
{
	fun1();
}
void sum()
{
	int sum = 0;
	for (int i = 0; i <= 100; i++)
	{
		sum += i;
	}
	fun();
	return sum;
}
int main()
{
	printf("hello world1\n");
	printf("hello world2\n");
	printf("hello world3\n");
	printf("hello world4\n");
	printf("hello world5\n");
	sum();
	printf("hello world6\n");
	printf("hello world7\n");
	printf("hello world8\n");
	system("pause");
	return 0;
}
