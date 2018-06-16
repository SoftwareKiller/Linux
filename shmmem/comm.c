#include"comm.h"

int main( void )
{
  //创建共享内存
  key_t key = ftok(PATHNAME, PROJ_ID);
  if( key < 0){
    perror("ftok");
    exit(1);
  }

  int shmid = shmget(key, sizeof(stu_t), IPC_CREAT|IPC_EXCL|0644);
  if(shmid < 0){
    perror("shmget");
    exit(1);
  }
  printf("cerate ok\n");
  return shmid;

  printf("create ok\n");

}


