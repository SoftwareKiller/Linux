#ifndef _COMM_H_
#define _COMM_H_

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<sys/shm.h>

#define PATHNAME "./"
#define PROJ_ID 0x12

typedef struct stu{
	char name[32];
	int age;
}stu_t;

int createShm(int size);
int destroyShm(int shmid);
int getShm(int size);

#endif
