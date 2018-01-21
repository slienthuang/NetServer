#include <stdio.h>
#include <stdlib.h>  //standrad library 如:exit(int state) malloc()  realloc()   标准数据类型 size_t
#include <string.h>
#include <unistd.h>  //unix standrad library unix系统标准库 符合posix操作系统所带如的针对系统调用的封装函数 如fork,pipe,i/o
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
	int server_sock; 
	int client_sock; 

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	char message[] = "hello world";

	server_sock = socket(PF_INET,SOCK_STREAM,0);

	if (server_sock==-1)
		printf("server_sock error1");

	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port = htons(6888);

	if(bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
		printf("bind error1");

	if(listen(server_sock,5)==-1)
		printf("listen error1");

	client_addr_size = sizeof(client_addr);
	client_sock = accept(server_sock,(struct sockaddr*)&client_addr,&client_addr_size);

	write(client_sock,message,sizeof(message));

	close(client_sock);
	close(server_sock);
	return 0;
}