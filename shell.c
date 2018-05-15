#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<ctype.h>

#define IN 1
#define OUT 0

void do_exec(int argc, char* argv[])
{
	pid_t id;
	if( (id=fork()) == 0)
	{
		execvp(argv[0],argv);
		printf("command %s not found\n",argv[0]);
		exit(1);
	}
	int s;
	waitpid(id, &s, 0);
}

void do_prase(char *buf)
{
	char* argv[8];
	int argc = 0;
	int flag = OUT;
	int i = 0;
	for(i = 0; buf[i] !='\0'; i++)
	{
		if(!isspace(buf[i]) && flag == OUT){
			flag = IN;
			argv[argc++] = &buf[i];
		}else if(isspace(buf[i])){
			flag = OUT;
			buf[i] = '\0';
		}
	}	
	argv[argc] = NULL;
	do_exec(argc, argv);
}

int main()
{
	char buf[100];
	while(1)
	{
		printf("冰可乐>");
		memset(buf, 0x00, sizeof(buf));
		scanf("%[^\n]%*c",buf);
		if( strncmp(buf, "exit", 4) == 0)
			exit(0);
		do_prase(buf);
	}
	return 0;
}

