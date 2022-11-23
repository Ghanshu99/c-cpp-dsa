#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<string.h>
int main()
{
int clientSocketDescriptor;
int serverSocketDescriptor;
struct sockaddr_in serverSocketInformation;
char request[5000];
char response[5000];

clientSocketDescriptor=socket(AF_INET,SOCK_STREAM,0);

serverSocketInformation.sin_family=AF_INET;
serverSocketInformation.sin_port=htons(5050);
serverSocketInformation.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clientSocketDescriptor,(struct sockaddr *)&serverSocketInformation,sizeof(serverSocketInformation));
strcpy(request,"/");
send(clientSocketDescriptor,request,strlen(request)+1,0);
recv(clientSocketDescriptor,response,sizeof(response),0);
printf("Response received\n");
printf("%s\n",response);
return 0;
}
