#include<iostream>
using namespace std;
void func(int a);
template<class T>
void TFunc(const T& a);
//�����Ͷ������һ���ļ�--���������
template<class T>
void TFunc(const T& a)
{
	cout << "TFunc->" << a << endl;
}