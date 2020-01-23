#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
  int clientSocket,port;
  printf("Enter port to send data: ");
  scanf("%d",&port);
  int buffer[6];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  clientSocket = socket(PF_INET,SOCK_STREAM,0);
  serverAddr.sin_family=AF_INET;
  serverAddr.sin_port=htons(port);
  serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  addr_size=sizeof(serverAddr);
  connect(clientSocket,(struct sockaddr*)&serverAddr,addr_size);
  printf("Enter numbers\n");
  for(int i=0;i<5;i++){
    scanf("%d", &buffer[i]);
  }
  send(clientSocket,buffer,sizeof(buffer),0);
  int res[6];
  recv(clientSocket,&res,sizeof(res),0);
  printf("Sum recieved from server: %d\n",res[5]);
  printf("Sorted array:\n");
  for(int i=0;i<5;i++){
    printf("%d\n", res[i]);
  }
  return 0;
}
