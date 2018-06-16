#include"comm.h"

static int commShm(int size, int flags)
{
    key_t key = ftok(PATHNAME, PROJ_ID);
    if( key < 0){
        perror("ftok");
        return -1;
    }

    int shmid = shmget(key, 36, 0);
    if(shmid < 0){
	perror("shmget");
	exit(1);
    }
    printf("cerate ok\n");
    return shmid;
}

int getShm(int size)
{
    printf("client get\n");
    return commShm(size, 0);
} 

int main()
{
    int shmid = getShm(36);
    stu_t* addr = (stu_t*)shmat(shmid, NULL, 0);
    if(NULL == addr){
	perror("shmat");
	exit(1);
    }
    sleep(3);
    int i = 0;
    while(1){
	sprintf(addr->name,"ABC%d",i);
	i++;
    }

    shmdt(addr);
    sleep(2);
    return 0;
}

