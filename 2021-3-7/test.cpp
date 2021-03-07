#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;

//class Time
//{
//public:
//	Time(int hour=0,int second=0)//假如没有默认参数，就必须自己定义，有默认参数不用自己定义，
//		: _hour(hour)
//		, _second(second)
//	{
//		cout << "Time(int _hour=0,int second=0)" << endl;
//	}
//	Time& operator=(const Time& t)
//	{
//		cout << "Time& operator=(const Time& t)" << endl;
//		return *this;
//	}
//private:
//	int _hour;
//	int _second;
//};
//class Date
//{
//public:
//	//int i;
//	//i=10;
//	//函数体内初始化
//	Date(int year, int month, int day,int hour,int second)
//		:_n(10)
//		, _ref(day)
//		, _t(hour,second)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		//_n=10;//不行
//	}
	//int i=10;
	//初始化列表--可以认为是对象的每个成员变量定义初始化的地方
	/*Date(int year, int month, int day，int hour)
		:_year(year)
		, _month(month)
		, _day(day)
		, _n(10)
		,_t(hour)
	    {}*/
//class Date
//{
//public:
//	//推荐使用初始化列表
//	Date(int year, int month, int day, int hour, int second)//调一次Time的构造函数
//		//:_t(hour,second)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		//Time _t(hour,second);//在调一次Time的构造函数
//		//_t = t;//调用赋值操作函数
//	}
//private:
//	int _year;//声明，不是定义，未分配空间
//	int _month;
//	int _day;
//
	//以下对象必须在定义的时候初始化
	//const int _n;//const类型的变量必须在定义的时候初始化，必须在初始化列表中出现
	//int& _ref;//必须在初始化列表中出现
//	Time _t;//没有默认构造函数(不用参数调用的那个)的的对象，必须在初始化列表初始化
//};





//class A
//{
//public:
//	explicit A(int a)
//		:_a(a)
//	{}
//	A(const A& aa)
//		: _a(aa._a)
//	{}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	//Date d1(2021,3,4,10,1);//整个对象定义的位置
//	A aa1(1);//它的生命周期在main函数域
//	//A(1);//匿名对象，它的生命周期在这一行
//	//int i=0;
//	//double d=i;
//	A aa2 = 2;//隐式类型转换，也是调用构造函数---》先构造一个A(2)匿名临时对象，再用这个临时对象去拷贝构造aa2.最后呢，编译器把这两个过程优化合并了，直接调了构造函数
//	
//	aa1.Print();
//	aa2.Print();
//	system("pause");
//}




//class string
//{
//string(const char* str)
//private:
//	//...
//};
//int main()
//{
//	string s1("hello");
//	string s2 = "world";
//}

//class A
//{
//public:
//	A()
//	{
//		++_countA;
//	}
//	A(const A& aa)
//	{
//		++_countA;
//	}
//	//相比非静态成员函数，没有this指针
//	//所以它不能访问其他的非静态成员
//	static int GetCountA()//私有的外界访问不了，可以用函数去访问它
//	{
//		//x=10;
//		return _countA;
//	}
//private:
//	static int _countA;//静态成员变量属于类的所有对象，属于整个类
//	int x;
//};
////定义初始化
//int A:: _countA = 0;
//
//int main()
//{
//	A aa;
//	//A::_countA = 1;//只能访问公有的变量
//	cout << sizeof(A) << endl;
//	A a1;
//	A a2;
//	A a3;
//	A a4(a1);
//	A();
//
//	//如果没有访问限定符的限制，指定类域就可以访问静态成员
//	//指定类域有2种方式，对象或者类型
//	//cout << a1._countA << endl;//只能访问公有的变量
//	//cout<<A._countA<<endl;//只能访问公有的变量
//	cout << a1.GetCountA() << endl;//不是在对象里面去找，是为了告诉编译器突破类域
//	cout << A::GetCountA() << endl;//static定义的函数，只要突破类域就能调
//	return 0;
//}

//static int a;
//int main()
//{
//	a = 10;
//}



//C++11
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//class A
//{
//public:
//	A(int a=10) //有构造函数，缺省值则不起作用
//		:_a(a)
//	{}
//	void Print()
//	{
//		cout << _a << endl;
//		cout << bb._b << endl;
//		cout << p << endl;
//	}
//private:
//	//非静态成员变量，可以在成员声明时给缺省值
//	//强调一下，这里不是初始化，这里是给的缺省值
//	//构造函数在没有给值的情况下，就会用这里的缺省值
//	//弥补C++98中默认构造函数，内置类型不处理的问题
//	int _a = 1;
//	//B bb;
//	B bb = 1;
//	int*p = (int*)malloc(4);
//
//};
//
//int main()
//{
//	A aa1;
//	aa1.Print();
//}
//默认生成A构造函数有点偏心，针对内置类型没有处理，自定义类型bb调用它的默认构造函数初始化
//C++中如果内置类型的成员变量给你缺省值那么也要处理，按缺省值初始化

//class Sum
//{
//public:
//	Sum()
//	{
//		_ret += _i;
//		++_i;
//	}
//	static int GetRet()
//	{
//		return _ret;
//	}
//private:
//	static int _i;
//	static int _ret;
//};
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//
//class Solution{
//public:
//	int Sum_Solution(int n){
//		//Sum arr[10];//调n次构造函数
//		Sum*p = new Sum[n];
//
//		return Sum::GetRet();
//	}
//};
//
//int main()
//{
//	cout << Solution().Sum_Solution(5) << endl;
//}


class Date
{
	friend  ostream& operator<<(ostream& out, const Date& d);
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d)//写在外面，因为现在结构体内，this占据了第一个位置。并且要访问私有变量，需要成为有元函数
{
	cout << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}
int main()
{
	Date d1;
	Date d2(2020,3,4);
	//d1.operator<<(cout);
	//d1 << cout;
	cout << d1<<d2;
}