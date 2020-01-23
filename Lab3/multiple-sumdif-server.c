#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
  int welcomeSocket,newSocket,newSocket1,port;
  printf("Enter port to listen on: ");
  scanf("%d",&port);
  int buffer[2];
  int buffer1[2];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  struct sockaddr_storage serverStorage1;
  socklen_t addr_size;
  socklen_t addr_size1;
  welcomeSocket = socket(PF_INET,SOCK_STREAM,0);
  serverAddr.sin_family=AF_INET;
  serverAddr.sin_port=htons(port);
  serverAddr.sin_addr.s_addr= inet_addr("127.0.0.1");
  bind(welcomeSocket,(struct sockaddr*)& serverAddr,sizeof(serverAddr));
  if(listen(welcomeSocket,5)==0){
    printf("Listening\n");
  }
  else{
    printf("Error\n");
  }
  addr_size=sizeof(serverStorage);
  addr_size1=sizeof(serverStorage1);
  newSocket = accept(welcomeSocket,(struct sockaddr*)&serverStorage,&addr_size);
  newSocket1 = accept(welcomeSocket,(struct sockaddr*)&serverStorage1,&addr_size1);
  recv(newSocket,buffer,sizeof(buffer),0);
  recv(newSocket1,buffer1,sizeof(buffer1),0);
  int sum=(buffer[0])+(buffer[1]);
  int diff=(buffer1[0])-(buffer1[1]);
  send(newSocket,&sum,sizeof(int),0);
  send(newSocket1,&diff,sizeof(int),0);
  return 0;
}
