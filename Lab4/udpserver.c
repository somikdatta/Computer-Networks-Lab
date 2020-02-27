#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{ char buf[1024],buf1[1024];
  int listeningSocket,newSocket;
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;
  listeningSocket = socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7070);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  bind(listeningSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
  addr_size = sizeof(serverStorage);
  recvfrom(listeningSocket,buf,1024,0,(struct sockaddr*)&serverStorage,&addr_size);
  close(listeningSocket);
  return 0;
}
