#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>
#define PORT 4345
#define SA struct sockaddr
int main()
{
 int sockfd;
 struct sockaddr_in servaddr;
 sockfd=socket(AF_INET,SOCK_STREAM,0);
char buffer[100];
char b[100];
 if(sockfd==-1)
 {
  puts("socket creation failed.........\n");
  exit(0);
 }
 puts("socket created successfully........\n");
 bzero(&servaddr,sizeof(servaddr));
 servaddr.sin_family=AF_INET;
 servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 servaddr.sin_port=htons(PORT);
 if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr))!=0)
 {
  puts("connection failed.....\n");
  exit(0);
 }
 puts("connection successfully.....\n");
scanf("%s",buffer);
//len=sizeof(servaddr);
send(sockfd,buffer,sizeof(buffer),0);
recv(sockfd,b,sizeof(b),0);
puts(b);
close(sockfd);
}
