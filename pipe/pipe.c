#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)
//父子进程间通信
int main(int argc, char *argv[])
{
	int pipefd[2];
	if(pipe(pipefd) == -1)
		ERR_EXIT("pipe");

	pid_t pid = fork();
	char buf[128];
	memset(buf, 0x00, sizeof(buf));
	if( pid == -1)
		ERR_EXIT("fork");

	if( pid == 0){
		close(pipefd[0]);
		strcpy(buf, "Hey, Coder");
		write(pipefd[1], buf, strlen(buf));
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}

	close(pipefd[1]);
	read(pipefd[0], buf, 128);
	printf("%s\n", buf);

	return 0;
}

