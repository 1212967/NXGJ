/*
��ӭ�鿴web.exe��Դ����
����ʹ�����еĴ��룬����Ҫע������
����QQ3239088523
�����£�2020.10.29
�޸������Ӳ�����յ����� 
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
int found=0; 
int UI()
{
	cout<<"Web.exe for NXGJ"<<endl;
	cout<<"made by 1212967"<<endl;
	cout<<"----------------------"<<endl;
}
int getdata() //��ȡ��ҵ�б�ĺ��� 
{
	ifstream get("data.txt");
	std::ostringstream tmp; 
   	tmp << get.rdbuf(); 
   	str = tmp.str();
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
    	cout<<"û���ҵ�..."<<endl;
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
		 Sleep(1000); 
	}	
}
int main() //������ 
{
	system("cls");
	getdata();
	while(1)
	{ 
		UI();
		cout<<"��ҵ�б�"<<endl;
		cout<<str<<endl;
		cout<<"Ҫ�鿴���˵�����(����quit����������)��";
		cin>>name; 
		if(name=="quit")
		{
			system("cls"); 
			return 0; //�������� 
		}
		search();
		print();
		ie();
		system("pause"); //"�����������"
		system("cls"); //���� 
		url=0;//��λ ֮ǰ���Ǹ�λ�����ظ��򿪴��� 
	}
	return 0;
}
