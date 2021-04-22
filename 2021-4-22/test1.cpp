#define _CRT_SECURE_NO_WARNINGS 1
#include"template.h"
int main()
{
	/*func(10);
	TFunc(10);
	TFunc(10.11);
	return 0;*/
	cout << "正常输出" << endl;
	cerr<< "错误输出" << endl;
	clog<< "日志输出" << endl;
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n",n);
	}
	return 0;
}
