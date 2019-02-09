#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
int main(int count,char **args){
	if(count<1)	return -1;

	int fd=open(args[1],O_RDONLY|O_CREAT);
	if(fd==-1){
		printf("cant read fileDescriptor");
	return -1;
	}

	char ch;
	printf("heere \n");
	while(read(fd,&ch,1) )
		putchar(ch);

	close();

	
}
