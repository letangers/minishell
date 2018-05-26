#include "parse.h"
#include <iostream>
#include <string>
#include <csignal>
using namespace std;

void handle(int sig){
	cout<<endl<<"[minishell]$";
	cin.clear();
	cin.sync();
}

int main(void){
//shel主循环

	signal(SIGINT,handle);
	signal(SIGQUIT,SIG_IGN);
	while(true)
	{
		cout<<"[minishell]$";
		cin.clear();
		cin.sync();
		if(read_command()==-1)
		{
			cout<<"读取命令出错"<<endl;
			continue;
		}
		if(parse_command()==-1)
		{
			cout<<"解析命令出错"<<endl;
			continue;
		}
		if(execute_command()==-1)
		{
			cout<<"执行命令时出错"<<endl;
			continue;
		}
	}
	cout<<endl<<"exit"<<endl;
	return 0;
}

int read_command(void){
//读取命令,成功返回0，失败或者读取到文件结束（EOF)返回-1
	if(cin.eof())
		return -1;
	cmdline="";
	getline(cin,cmdline);
	return 0;
}

int parse_command(void){
//解析命令,成功则返回解析到的命令个数，失败返回-1
	for (int i=0;i<=index;i++)
		arg.args[i]="";
	index=0;
	int last=0;
	for(unsigned int i=0;i<cmdline.length();i++){
		if(cmdline[i]==' '||cmdline[i]=='\t')
			last=1;
		else{
			if(last==1)
				arg.args[++index]+=cmdline[i];
			else
				arg.args[index]+=cmdline[i];
			last=0;
		}
	}
	
	for(int i=0;i<=index;++i)
		cout<<arg.args[i]<<" ";
	cout<<endl;
	return index;
}

int  execute_command(void){
//执行命令，成功返回0，失败返回-1
	return 0;
}
