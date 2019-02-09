#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc , char **args){
	int fileDescriptor,fileDescriptor2;
	char ch;
	if(argc<2)
		return -1;
	errno=0;
	fileDescriptor=open(args[1],O_RDONLY);
	fileDescriptor2=open(args[2],O_WRONLY);
	if(fileDescriptor==-1 ||fileDescriptor2 ==-1 ){
		printf("Failed to open fileDescriptors\n");
		printf(" err [%s]\n",strerror(errno) );

		return -1;
	}
	


	//was succesful in opening a stream... can read now
	/* fd,buffer,count*/
	printf("%d fd\n",fileDescriptor);
	/* fileDescriptor,buffer,size*/
	while(read(fileDescriptor,&ch,1))
	/* writing to the stream of the second file*/
		write(fileDescriptor2,&ch,1);
	close();
	close();
	return 1;

}
