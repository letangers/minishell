#include "parse.h"
#include <iostream>
#include <string>
#include <signal.h>

using namespace std;

void handle(int sig){
	cout<<endl<<"[minishell]&";
	cin.sync();
}

int main(void){
//shel主循环

	signal(SIGINT,handle);
	signal(SIGQUIT,SIG_IGN);
	while(true){
		cout<<"[minishell]$";
		cin.sync();
		if(read_command()==-1)
			break;
		parse_command();
		execute_command();
	}
	cout<<endl<<"exit"<<endl;
	return 0;
}

int read_command(void){
//读取命令,成功返回0，失败或者读取到文件结束（EOF)返回-1
	cout<<"[waitting a command]";
	cin.getline(cmdline,MAXLINE);
	if(cin.eof())
		return -1;
	cout<<cmdline<<endl;
	return 0;
}

int parse_command(void){
//解析命令,成功则返回解析到的命令个数，失败返回-1
	
	return 0;
}

int  execute_command(void){
//执行命令，成功返回0，失败返回-1
	return 0;
}
