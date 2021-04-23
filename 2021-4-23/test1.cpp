#define _CRT_SECURE_NO_WARNINGS 1
//#include"template.h"
//int main()
//{
	///*func(10);
	//TFunc(10);
	//TFunc(10.11);
	//return 0;*/
	//cout << "正常输出" << endl;
	//cerr<< "错误输出" << endl;
	//clog<< "日志输出" << endl;
	///*int n = 0;
	//while (scanf("%d", &n) != EOF)
	//{
	//	printf("%d\n",n);
	//}*/
	//int n = 0;
	//while (cin >> n)
	//{
	//	cout << n << endl;
	//}
	//return 0;
//}
//使用文件IO流用文本及二进制方式演示读写配置文件
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct ServerInfo
{
	char _ip[32];//ip
	int _port;//端口
};
struct ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_configfile(filename)
	{}
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_configfile);
		ofs.write((char*)&info,sizeof(ServerInfo));
	}
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_configfile);
		ofs << info._ip<<" ";
		ofs << info._port;
	}
	void ReadBin( ServerInfo& info)
	{
		ifstream ifs(_configfile);
		ifs.read((char*)&info, sizeof(ServerInfo));
	}
	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_configfile);
		ifs>>info._ip;
		ifs>>info._port;
	}

private:
	string _configfile;//配置文件
};
int main()
{
	ServerInfo myInfo = {"192.168.1.1",8000};
	ConfigManager cm("serve.config");
	//cm.WriteBin(myInfo);
	ServerInfo yourInfo;
	cm.ReadBin(yourInfo);

	//ServerInfo myInfo = {"192.168.1.1",8000};
	//ConfigManager cm("serve.config");
	////cm.WriteText(myInfo);
	//ServerInfo yourInfo;
	//cm.ReadText(yourInfo);
}

//int main()
//{
//	char sqlstr[256];//不知道开多少空间
//	char name[100];
//	scanf("%s",name);
//	sprintf(sqlstr,"select * from t_student where name='%s'",name);
//	printf("%s\n",sqlstr);
//}
//int main()
//{
//	stringstream ss;
//	string name;
//	cin >> name;
//	ss << "select * from t_student where name=''";
//	ss << name;
//	ss << "'";
//
//	string sq1 = ss.str();
//	cout << sq1;
//}
//int main()
//{
//	stringstream ss("【匿名】yiyi 21:50:28 吃饭");
//	string name;
//	string time;
//	string message;
//	ss >> name;
//	ss >> time;
//	ss>> message;
//}

