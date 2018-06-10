#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t id = fork();
	if(id == -1){
		perror("fork");
		return 1;
	}
	else if(id == 0){
		printf("child pid: %d\n",getpid());
		sleep(3);
		exit(0);
	}else{
		printf("parents pid:%d\n",getpid());
		sleep(30);
		exit(EXIT_SUCCESS);
	}
	return 0;
}

