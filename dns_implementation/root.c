#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#define SA struct sockaddr
#define PORT 4444

int main()
{    
  int sockfd,connfd,len;
  struct sockaddr_in servaddr,cli;
  sockfd=socket(AF_INET,SOCK_STREAM,0);
FILE *fptr;
  char a[100];
  char b[100];
char s[100];

  if(sockfd==-1)
  {
    puts("socket creation failed");
    exit(0);
  }
  puts("socket created successfully............");
  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=htons(PORT);
  servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
  if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0)
  {
   puts("bind failed....");
   exit(0);
  }
  printf("bind successfull......");
  if((listen(sockfd,5))!=0)
  {
   puts("listening failed ........");
    exit(0);
  }
  puts("listening successfull");
  len=sizeof(cli);
  connfd=accept(sockfd,(SA*)&cli,&len);
  if(connfd<0)
  {
    puts("connection failed..");
    exit(0);
  }

puts("connection successfull....");

fptr=fopen("sitename1.txt","r");
  if(fptr)
  printf("file opened");
recv(connfd,s,sizeof(s),0);
int found=0;
 while(fscanf(fptr,"%s",a)!=EOF)
{

if(strcmp(s,a)==0)
{
fscanf(fptr,"%s",b);
found=1;
break;

}
}
if(!found)
strcpy(b,"not found");
fclose(fptr);
puts(b);
send(connfd,b,sizeof(b),0);
close(sockfd);
}
