#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define ERR_EXIT(m)\
	do{\
		perror(m);\
		exit(1);\
	}while(0)

int main()
{
	int wfd = open("mypipe",O_WRONLY);
	if(wfd < 0)
		ERR_EXIT("open");

	char buf[1024];
	while(1){
		buf[0] = 0;
		printf("Come ,Let's talk# ");
		fflush(stdout);
		ssize_t s = read(0, buf, sizeof(buf)-1);
		if( s > 0){
			buf[s] = 0;
			write(wfd, buf, strlen(buf));
		}else{
			ERR_EXIT("read");
		}
	}

	close(wfd);	
	return 0;
}
