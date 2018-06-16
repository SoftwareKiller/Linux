#include"comm.h"

static int commShm(int size, int flags)
{
    key_t key = ftok(PATHNAME, PROJ_ID);
    if( key < 0){
        perror("ftok");
        exit(1);
    }

    int shmid = shmget(key, 36, flags);
    if(shmid < 0){
	perror("shmget");
	exit(1);
    }
    printf("cerate ok\n");
    return shmid;
}

int createShm(int size)
{
    printf("certe\n");
    return commShm(size, 0);
}

int destroyShm(int shmid)
{
	int del = shmctl(shmid, IPC_RMID, NULL);
	if(del < 0)
	{
		perror("shmctl");
		exit(19);
	}
	return 0;
}

int main()
{
    int shmid = createShm(36);

    stu_t* addr = (stu_t*)shmat(shmid, NULL, 0);
    if(NULL == addr)
    {
	perror("shmat");
	return -1;
    }
    int i = 3;
    while(i--){
	printf("come to while\n");
	sleep(1);
	printf("%s\n",addr->name);
    }
    shmdt(addr);
    sleep(2);
    printf("Program is over\n");
    //destroyShm(shmid);
    return 0;
}

