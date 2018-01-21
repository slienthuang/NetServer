#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
	int server_sock;
	struct  sockaddr_in server_addr;
	char message[30];
	int str_len;

	server_sock=socket(PF_INET,SOCK_STREAM,0);

	if(server_sock==-1)
		printf("server_sock error");

	memset(&server_addr,0,sizeof(server_addr));

	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	server_addr.sin_port = htons(6888);

	if(connect(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
		printf("connect error1");

	str_len = read(server_sock,message,sizeof(message));
	if(str_len==-1)
		printf("read error1");

	printf("message from server:%s \n",message);
	close(server_sock);
	return 0;


}
