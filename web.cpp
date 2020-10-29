/*
欢迎查看web.exe的源代码
可以使用其中的代码，但是要注明作者
作者QQ3239088523
最后更新：2020.10.29
修复了链接不被清空的问题 
For NXGJ 
*/ 
//头文件 
#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <shellapi.h> 
//命名空间 
using namespace std;
string str; //数据 
string name; //同学姓名 
char end[50]="-----"; //结束标志 
char *p; //指针 
string urls[30]; //存储找到的地址 
int url=0; //查找到的地址的数量
int found=0; 
int UI()
{
	cout<<"Web.exe for NXGJ"<<endl;
	cout<<"made by 1212967"<<endl;
	cout<<"----------------------"<<endl;
}
int getdata() //获取作业列表的函数 
{
	ifstream get("data.txt");
	std::ostringstream tmp; 
   	tmp << get.rdbuf(); 
   	str = tmp.str();
}
int search() //主要算法 通过姓名定位并提取url 
{
	string::size_type idx;
	ifstream file;
	file.open("data.txt",ios::in);
  	if(!file.is_open())
        return 0;
	std::string strLine;
    while(getline(file,strLine))
    { 
    	if(strLine.empty())
            continue;
		//cout<<strLine <<endl;
		//p=(strstr(strLine,name);
		else if(strLine==name)
		{
			found=1;
			while(1)
			{
				getline(file,strLine);
				idx=strLine.find("http");
				if(idx == string::npos )
				{
					//do noting	
				}
				else
				{
					urls[url]=strLine;
					url++;
				}
				
				idx=strLine.find("-----");
				if(idx == string::npos )
				{
				}
				else
				{
					//cout<<url;
					return 0; 
				}
			}
		}              
    }
    if(!found)
    {
    	cout<<"没有找到..."<<endl;
	}
	//file.close();
}
int print() //输出地址的函数 
{
	int b=0;
	for(int a=0;a<url;a++)
	{
		cout<<urls[a]<<endl; 
	}
}
int ie() //用浏览器打开地址的函数 
{
	for(int a=0;a<url;a++)
	{
		 ShellExecute(NULL,"open","explorer.exe",urls[a].c_str(), NULL, SW_SHOW);
		 Sleep(1000); 
	}	
}
int main() //主函数 
{
	system("cls");
	getdata();
	while(1)
	{ 
		UI();
		cout<<"作业列表："<<endl;
		cout<<str<<endl;
		cout<<"要查看的人的姓名(输入quit返回主程序)：";
		cin>>name; 
		if(name=="quit")
		{
			system("cls"); 
			return 0; //结束程序 
		}
		search();
		print();
		ie();
		system("pause"); //"按任意键继续"
		system("cls"); //清屏 
		url=0;//复位 之前忘记复位导致重复打开错误 
	}
	return 0;
}
