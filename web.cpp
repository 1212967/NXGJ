/*
��ӭ�鿴web.exe��Դ����
����ʹ�����еĴ��룬����Ҫע������
����QQ3239088523
�����£�2020.9.18
For NXGJ 
*/ 
//ͷ�ļ� 
#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <shellapi.h> 
//�����ռ� 
using namespace std;
string str; //���� 
string name; //ͬѧ���� 
char end[50]="-----"; //������־ 
char *p; //ָ�� 
string urls[30]; //�洢�ҵ��ĵ�ַ 
int url=0; //���ҵ��ĵ�ַ������ 
int getdata() //��ȡ��ҵ�б�ĺ��� 
{
	ifstream get("data.txt");
	std::ostringstream tmp; 
   	tmp << get.rdbuf(); 
   	str = tmp.str();
	return 0;
}
int search() //��Ҫ�㷨 ͨ��������λ����ȡurl 
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
	//file.close();
}
int print() //�����ַ�ĺ��� 
{
	int b=0;
	for(int a=0;a<url;a++)
	{
		cout<<urls[a]<<endl; 
	}
}
int ie() //��������򿪵�ַ�ĺ��� 
{
	for(int a=0;a<url;a++)
	{
		 ShellExecute(NULL,"open","explorer.exe",urls[a].c_str(), NULL, SW_SHOW);
		 _sleep(1000); 
	}	
}
int main() //������ 
{
	getdata();
	while(1)
	{ 
		cout<<"��ҵ�б�"<<endl;
		cout<<str<<endl;
		cout<<"Ҫ�鿴���˵�����(����quit�˳�)��";
		cin>>name; 
		if(name=="quit")
		{
			return 0; //�������� 
		}
		search();
		print();
		ie();
		system("pause"); //"�����������"
		system("cls"); //���� 
	}
	return 0;
}
