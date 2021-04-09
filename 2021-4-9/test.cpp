#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

namespace std
{
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_front(0);

		// 遍历方式1
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;


		// 遍历方式2
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator pos = std::find(lt.begin(), lt.end(), 2);
		if (pos != lt.end())
		{
			lt.insert(pos, 20);
		}

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			if (*it % 2 == 0)
			{
				it = lt.erase(it);
			}
			else
			{
				++it;
			}
		}

		// 遍历方式2
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

namespace bit
{
	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			// const T& it.operator*()
			//*it = 1;
			cout << *it << endl;
			++it;
		}
		cout << endl;
	}

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it = 1;
			cout << *it << endl;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

int main()
{
	bit::test_list1();

	return 0;
}