#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>

void get_line(FILE* fp, char* buf, int len)
{
	memset(buf, 0x00, len);
	char c;
	int i = 0;
	do{
		c=fgetc(fp);
		if( c == EOF )
			exit(0);
		buf[i++] = c;
	}while(c!='\n' && i<len);
}

int main( void )
{
	char buf[1024] = {};
	
	printf("要显示的文件名：");
	scanf("%s", buf);
	printf("buf=[%s]\n", buf);
	FILE* fp = fopen(buf, "r");
	if(fp == NULL){
		fprintf(stderr, "%s 不存在\n", buf);
		exit(1);
	}

	while(1){
		get_line(fp, buf, 1024);
		int s = 0;
		int i = 0;
		for(i=0; buf[i] != '\0'; ++i){
			if( isspace(buf[i]) ){
				putchar(buf[i]);
				fflush;
				s = 0;
			}else if( !isspace(buf[i]) && s == 0 ){
				for(; !isspace(buf[i]); ++i){
					putchar(buf[i]);
					fflush;
					s = 1;
				}
				s = 0;
				sleep(1);
				--i;
			}
		}
	}
	fclose(fp);
}

