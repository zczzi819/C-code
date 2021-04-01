#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//模拟实现简单的string(不包含增删查改)
//深浅拷贝
namespace bit{
	class string{
	public:
		string()
			:_str(nullptr)
		{

		}
		string(char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str,str);
		}
		~string()
		{
			delete[] _str;
		}
		char& operator[](size_t i)
		{
			return _str[i];
		}
	private:
		char* _str;
	};
}

int main()
{
	bit::string s1("hello");
	s1[0] = 'x';
	bit::string s2 = "world";
	bit::string s3;
}
