#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{ char buf[1024],buf1[1024];
  int listeningSocket,newSocket,f=0, l, palin=1;
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
  l=strlen(buf)-1;
  // printf("l=%d\n", l);
  printf("Recieved: %s\n",buf);
  while(f<l){
    if(buf[f] != buf[l]){
      palin = 0;
      break;
    }
    else{
      f++;
      l--;
    }
  }
  sprintf(buf1,"%d",palin);
  sendto(listeningSocket,buf1,100,0,(struct sockaddr*)&serverStorage,addr_size);
  close(listeningSocket);
  return 0;
}
