#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
  char buf[1024],type[10];
  char buf1[1024];
  int clientSocket;
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  clientSocket = socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7070);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  addr_size = sizeof(serverAddr);
  printf("Enter message:");
  scanf("%s",buf );
  sendto(clientSocket,buf,100,0,(struct sockaddr*)&serverAddr,addr_size);
  close(clientSocket);
  return 0;
}
