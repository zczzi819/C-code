#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;

//class Time
//{
//public:
//	Time(int hour=0,int second=0)//����û��Ĭ�ϲ������ͱ����Լ����壬��Ĭ�ϲ��������Լ����壬
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
//	//�������ڳ�ʼ��
//	Date(int year, int month, int day,int hour,int second)
//		:_n(10)
//		, _ref(day)
//		, _t(hour,second)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		//_n=10;//����
//	}
	//int i=10;
	//��ʼ���б�--������Ϊ�Ƕ����ÿ����Ա���������ʼ���ĵط�
	/*Date(int year, int month, int day��int hour)
		:_year(year)
		, _month(month)
		, _day(day)
		, _n(10)
		,_t(hour)
	    {}*/
//class Date
//{
//public:
//	//�Ƽ�ʹ�ó�ʼ���б�
//	Date(int year, int month, int day, int hour, int second)//��һ��Time�Ĺ��캯��
//		//:_t(hour,second)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		//Time _t(hour,second);//�ڵ�һ��Time�Ĺ��캯��
//		//_t = t;//���ø�ֵ��������
//	}
//private:
//	int _year;//���������Ƕ��壬δ����ռ�
//	int _month;
//	int _day;
//
	//���¶�������ڶ����ʱ���ʼ��
	//const int _n;//const���͵ı��������ڶ����ʱ���ʼ���������ڳ�ʼ���б��г���
	//int& _ref;//�����ڳ�ʼ���б��г���
//	Time _t;//û��Ĭ�Ϲ��캯��(���ò������õ��Ǹ�)�ĵĶ��󣬱����ڳ�ʼ���б��ʼ��
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
//	//Date d1(2021,3,4,10,1);//�����������λ��
//	A aa1(1);//��������������main������
//	//A(1);//������������������������һ��
//	//int i=0;
//	//double d=i;
//	A aa2 = 2;//��ʽ����ת����Ҳ�ǵ��ù��캯��---���ȹ���һ��A(2)������ʱ�������������ʱ����ȥ��������aa2.����أ��������������������Ż��ϲ��ˣ�ֱ�ӵ��˹��캯��
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
//	//��ȷǾ�̬��Ա������û��thisָ��
//	//���������ܷ��������ķǾ�̬��Ա
//	static int GetCountA()//˽�е������ʲ��ˣ������ú���ȥ������
//	{
//		//x=10;
//		return _countA;
//	}
//private:
//	static int _countA;//��̬��Ա��������������ж�������������
//	int x;
//};
////�����ʼ��
//int A:: _countA = 0;
//
//int main()
//{
//	A aa;
//	//A::_countA = 1;//ֻ�ܷ��ʹ��еı���
//	cout << sizeof(A) << endl;
//	A a1;
//	A a2;
//	A a3;
//	A a4(a1);
//	A();
//
//	//���û�з����޶��������ƣ�ָ������Ϳ��Է��ʾ�̬��Ա
//	//ָ��������2�ַ�ʽ�������������
//	//cout << a1._countA << endl;//ֻ�ܷ��ʹ��еı���
//	//cout<<A._countA<<endl;//ֻ�ܷ��ʹ��еı���
//	cout << a1.GetCountA() << endl;//�����ڶ�������ȥ�ң���Ϊ�˸��߱�����ͻ������
//	cout << A::GetCountA() << endl;//static����ĺ�����ֻҪͻ��������ܵ�
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
//	A(int a=10) //�й��캯����ȱʡֵ��������
//		:_a(a)
//	{}
//	void Print()
//	{
//		cout << _a << endl;
//		cout << bb._b << endl;
//		cout << p << endl;
//	}
//private:
//	//�Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ȱʡֵ
//	//ǿ��һ�£����ﲻ�ǳ�ʼ���������Ǹ���ȱʡֵ
//	//���캯����û�и�ֵ������£��ͻ��������ȱʡֵ
//	//�ֲ�C++98��Ĭ�Ϲ��캯�����������Ͳ����������
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
//Ĭ������A���캯���е�ƫ�ģ������������û�д����Զ�������bb��������Ĭ�Ϲ��캯����ʼ��
//C++������������͵ĳ�Ա��������ȱʡֵ��ôҲҪ������ȱʡֵ��ʼ��

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
//		//Sum arr[10];//��n�ι��캯��
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
ostream& operator<<(ostream& out, const Date& d)//д�����棬��Ϊ���ڽṹ���ڣ�thisռ���˵�һ��λ�á�����Ҫ����˽�б�������Ҫ��Ϊ��Ԫ����
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