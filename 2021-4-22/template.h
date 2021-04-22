#include<iostream>
using namespace std;
void func(int a);
template<class T>
void TFunc(const T& a);
//声明和定义放在一个文件--解决方案二
template<class T>
void TFunc(const T& a)
{
	cout << "TFunc->" << a << endl;
}