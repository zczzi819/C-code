#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<windows.h>
//using namespace std;
//C++������Ķ���������std��������ռ���
//int main()
//{
//	cout << "hello bit" << endl;
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<windows.h>
////�����ռ�-��
//namespace bit
//{
//	int scanf = 0;//����ȫ�ֱ������ŵ�bit�����ռ�����
//}
//int main()
//{
//	printf("%p\n",scanf);
//	printf("%d\n",bit::scanf);//::�������޶���
//	system("pause");
//	return 0;
//
//}

//#include<stdio.h>
//#include<windows.h>
////�����ռ�-��
//namespace bit
//{
//	int a= 0;
//	int b = 1;
//	int c = 2;
//
//}
//using bit::b; //�൱�ڰ�b����չ����ȫ������
//using namespace bit;
////�Ƽ�����Ŀ�У�������Ҫȫ��չ�������ʹ��1����2�ķ�ʽ
//int main()
//{
//	printf("%d\n", bit::a);//1.ֱ��ָ��
//	printf("%d\n", b);//2.����չ��
//	printf("%d\n",c);//3.ȫ��չ��
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
//	//1.���printf,�Զ�ʶ�����ͣ����������ʽ
//	//2.���������endl�����з���
//	//�Զ�ʶ��ԭ��cout cin������ʲô����Ͷ���+���������+��������
//	cout << "hello world"<<endl;
//	int i = 1;
//	double d = 2.222;
//	char ch = 48;
//	cout << i<<endl;
//	cout << d<<endl;
//	cout << ch<<endl;
//	cout << &i<<endl;//int* ʮ������
//	cout << &ch<<endl;//char* �ַ���
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
//	TestFunc();//û�д���ʱ��ʹ�ò���Ĭ��ֵ
//	TestFunc(1);//����ʱ��ʹ��ָ����ʵ��
//	TestFunc(1,2);
//	TestFunc(1,2,3);
//}