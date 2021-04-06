#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//反转字母
//class Solution{
//public:
//	bool isletter(char ch)
//	{
//		if (ch >= 'a'&&ch <= 'z')
//		{
//			return true;
//		}
//		if (ch >= 'A'&&ch <= 'Z')
//		{
//			return true;
//		}
//		return false;
//	}
//	string reverseOnlyletters(string s)
//	{
//		if (s.empty())
//		{
//			return s;
//		}
//		size_t begin = 0, end = s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end&&!isletter(s[begin]))
//			{
//				++begin;
//			}
//			while (begin < end&&!isletter(s[end]))
//			{
//				--end;
//			}
//			swap(s[begin], s[end]);
//			++begin;
//			--end;
//		}
//		return s;
//	}
//};
//int main()
//{
//	//Solution string1("a-bc-def-ghIj");
//	cout<<Solution().reverseOnlyletters("a-bc-def-ghIj") << endl;
//}
//字符串中唯一字符
//class Solution{
//public:
//	int firstUniqchar(string s)
//	{
//		int count[26] = { 0 };
//		for (auto ch : s)
//		{
//			count[ch - 'a']++;
//		}
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (count[s[i] - 'a'] == 1)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//};
//int main()
//{
//	cout << Solution().firstUniqchar("leetcode") << endl;
//}

//计算字符串最后一个单词的长度
//int main()
//{
//	string s;
//	getline(cin, s);
//	size_t pos = s.rfind(' ');
//	if (pos == string::npos)
//	{
//		cout << s.size() << endl;
//	}
//	else
//	{
//		cout << s.size() - pos - 1 << endl;
//	}
//}

//字符串相加
class Solution{
public:
	string addstring(string num1, string num2)
	{
		string ret;
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		char next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			char x1 = 0, x2 = 0;
			if (end1 >= 0)
			{
				x1 = num1[end1] - '0';
				--end1;
			}
			if (end2 >= 0)
			{
				x2 = num2[end2] - '0';
				--end2;
			}
			char retch = x1 + x2 + next;
			if (retch >= '10')
			{
				retch -= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			ret += (retch - '0');
		}
		if (next == 1)
		{
			ret += '1';
		}
		reverse(ret.begin(),ret.end());
		return ret;
	}
};
int main()
{
	cout << Solution().addstring("10","2") << endl;
}