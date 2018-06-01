#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int id;

void p()
{
	struct sembuf sem[1] = {0, -1, 0};
	semop(id, sem, 1);
}

void v()
{
	struct sembuf sem[1] = {0, 1, 0};
	semop(id, sem, 1);
}

void print(char c)
{
	int i = 0;
	for(; i<10; ++i)
	{
		p();
		printf("%c",c);
		fflush(stdout);
		sleep(rand()%3);
		printf("%c",c);
		fflush(stdout);
		v();
		sleep(rand()%3);
	}
}

union semnu{ int val; };

int main()
{
	srand(getpid());
	id = semget(219, 1, IPC_CREAT|0600);
	if( id == -1) perror("semget"),exit(1);

	union semnu sem;
	sem.val = 1;
	semctl(id, 0, SETVAL, sem);
	pid_t pid = fork();

	if(pid == 0){
		print('a');
	}else{
		print('b');
	}
	return 0;
}

