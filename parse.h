#ifndef _PARSE_H_
#define _PARSE_H_

  #define MAXLINE 1024   //输入的最大长度
  #define MAXARG 20  //设置每个简单命令的参数最多个数
  #define PIPELINE 5 //一个管道行中简单命令的最多个数
  #define MAXNAME 100 //IO重定向文件名的最大长度

#include <string>
using namespace std;
typedef struct args
{
	string args[MAXARG+1];
}ARGS;

//保存命令行输入
string cmdline;

//用来存放每个参数
ARGS arg;

//保存上一次的参数下标
int index=MAXARG;

void shell_loop(void);
int read_command(void);
int parse_command(void);
int execute_command(void);

#endif
