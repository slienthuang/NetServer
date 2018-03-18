//linux下文件操作帮助类

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//void error_handling(char* message);
/*int main(void)
{
	int fd;
	char buf[]="Let' go\n";

	fd = open("data.txt",O_CREAT|O_WRONLY|O_TRUNC);
	if(fd==-1)
	{
		//error_handling("open() error")
		printf("error1");
	}

	printf("file discriptor:%d\n",fd);

	if(write(fd,buf,sizeof(buf))==-1)
	{
		//error_handling("write() error")
		printf("error2");
	}

	close(fd);
	return 0;
}*/


// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <unistd.h>
 #define BUF_SIZE 100

int main(void)
{
	int fd;
	char buf[BUF_SIZE];
	fd=open("data.txt",O_RDONLY);
	read(fd,buf,sizeof(buf));
	printf("file data:%s",buf);
	close(fd);
	return 0;
}



// void error_handling(char* message)
// {
// 	// fputs(message,stderr)
// 	// fputc('\n',stderr);
// 	// 
// 	// 
// 	printf("error");
	
// 	exit(1)

// }


//测试
//
//