#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>

#define ERR_EXIT(m)\
	do{\
		perror(m);\
		exit(1);\
	}while(0)

int main()
{
	umask(0);
	if(mkfifo("mypipe", 0644) < 0)
		ERR_EXIT("mkfifo");

	int rfd = open("mypipe", O_RDONLY);
	if(rfd < 0)
		ERR_EXIT("open");

	char buf[1024];
	while(1){
		buf[0] = 0;
		printf("I am groot...\n");
		ssize_t s = read(rfd, buf, sizeof(buf)-1);
		if(s > 0){
			buf[s-1] = 0;
			printf("Groot say# %s\n",buf);
		}
		else if( s == 0){
			printf("Groot move, exit now!!!\n");
			exit(0);
		}else
			ERR_EXIT("read");
	}
	close(rfd);
	return 0;
}

