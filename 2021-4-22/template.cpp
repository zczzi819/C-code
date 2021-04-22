#define _CRT_SECURE_NO_WARNINGS 1
#include"template.h"
void func(int a)
{
	cout <<"func->"<< a << endl;
}
//template<class T>
//void TFunc(const T& a)
//{
//	cout << "TFunc->" << a << endl;
//}
////显示实例化--解决方案1
//template
//void TFunc<int>(const int& a);
//template
//void TFunc<double>(const double& a);