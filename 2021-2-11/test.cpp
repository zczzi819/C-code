#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<windows.h>
//using namespace std;
//C++库里面的东西都放在std这个命名空间中
//int main()
//{
//	cout << "hello bit" << endl;
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<windows.h>
////命名空间-域
//namespace bit
//{
//	int scanf = 0;//还是全局变量，放到bit命名空间域中
//}
//int main()
//{
//	printf("%p\n",scanf);
//	printf("%d\n",bit::scanf);//::域作用限定符
//	system("pause");
//	return 0;
//
//}

//#include<stdio.h>
//#include<windows.h>
////命名空间-域
//namespace bit
//{
//	int a= 0;
//	int b = 1;
//	int c = 2;
//
//}
//using bit::b; //相当于把b单独展开到全局域中
//using namespace bit;
////推荐在项目中，尽量不要全部展开，最好使用1或者2的方式
//int main()
//{
//	printf("%d\n", bit::a);//1.直接指定
//	printf("%d\n", b);//2.单独展开
//	printf("%d\n",c);//3.全部展开
//	system("pause");
//	return 0;
//
//}



//#include<iostream>
//#include"test.h"
//namespace N2
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//int main()
//{
//	printf("%d\n", N2::a);
//	printf("%d\n", N2::Add(1, 2));
//	printf("%d\n", N2::Mul(1, 2));
//	printf("%d\n", N2::N3::Sub(3, 4));
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//struct Student
//{
//	char name[10];
//	int age;
//};
//int main()
//{
//	//1.相对printf,自动识别类型，控制输出格式
//	//2.连续输出（endl代表换行符）
//	//自动识别原理，cout cin到底是什么？类和对象+运算符重载+函数重载
//	cout << "hello world"<<endl;
//	int i = 1;
//	double d = 2.222;
//	char ch = 48;
//	cout << i<<endl;
//	cout << d<<endl;
//	cout << ch<<endl;
//	cout << &i<<endl;//int* 十六进制
//	cout << &ch<<endl;//char* 字符串
//
//	cin >> i;
//	cin >> ch >> d;
//	cout << i << "--" << ch << "--" << d << endl;
//
//	struct Student s= {"Peter",18};
//	printf("name:%s age:%d\n",s.name,s.age);
//	cout << "name:" << s.name << "s.age:" << s.age << endl;
//	d = 10.0 / 3.0;
//	printf("%.2lf\n",d);
//	return 0;
//}


#include"test.h"

void TestFunc(int a=10 ,int b=20,int c=30)
{
	cout << "a="<<a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
//int main()
//{
//	TestFunc();//没有传参时，使用参数默认值
//	TestFunc(1);//传参时，使用指定的实参
//	TestFunc(1,2);
//	TestFunc(1,2,3);
//}