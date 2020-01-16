#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

int main(){
  int clientSocket,port;
  printf("Enter port to send data: ");
  scanf("%d",&port);
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  clientSocket = socket(PF_INET,SOCK_STREAM,0);
  serverAddr.sin_family=AF_INET;
  serverAddr.sin_port=htons(port);
  serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  addr_size=sizeof(serverAddr);
  connect(clientSocket,(struct sockaddr*)&serverAddr,addr_size);
  printf("What do I send to server?\n");
  scanf("%s", &buffer);
  send(clientSocket,buffer,sizeof(buffer),0);
  recv(clientSocket,buffer,1024,0);
  printf("Data recieved from server: %s\n",buffer);
  return 0;
}
