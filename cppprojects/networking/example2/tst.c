#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main()
{
char response[5000]; //5000 is very bad, we will change it later on
char request[5000];
int serverSocketDescriptor;
int clientSocketDescriptor;
struct sockaddr_in serverSocketInformation;
struct sockaddr_in clientSocketInformation;
int successCode;
int len;
serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,0);
if(serverSocketDescriptor<0)
{
printf("Unable to create socket\n");
return 0;
}
serverSocketInformation.sin_family=AF_INET;
serverSocketInformation.sin_port=htons(5050);
serverSocketInformation.sin_addr.s_addr=htonl(INADDR_ANY);
successCode=bind(serverSocketDescriptor,(struct sockaddr *)&serverSocketInformation,sizeof(serverSocketInformation));
if(successCode<0)
{
printf("Unable to bind socket at port 5050\n");
return 0;
}
listen(serverSocketDescriptor,10);
printf("TMServer is ready to accept request on port 5050\n");
len=sizeof(clientSocketInformation);
clientSocketDescriptor=accept(serverSocketDescriptor,(struct sockaddr *)&clientSocketInformation,&len);
if(clientSocketDescriptor<0)
{
printf("Unable to accept client connection");
close(serverSocketDescriptor);
return 0;
}
successCode=recv(clientSocketDescriptor,request,sizeof(request),0);
if(successCode>0)
{
printf("Request arrived\n");
printf("%s\n",request);
}
strcpy(response,"<!DOCTYPE html>");
strcat(response,"<html>");
strcat(response,"<head>");
strcat(response,"<title>whatever</title>");
strcat(response,"</head>");
strcat(response,"<body>");
strcat(response,"<h1>Welcome to thinking machines</h1>");
strcat(response,"</body>");
strcat(response,"</html>");
char header[5000];
strcpy(header,"HTTP/1.1 200 OK\n");
strcat(header,"Content Type:text/html\n");
strcat(header,"Content-Length:");
char responseLength[11];
sprintf(responseLength,"%d\n",strlen(response)+1);
strcat(header,responseLength);
strcat(header,"\n");  //a one line gap
successCode=send(clientSocketDescriptor,header,strlen(header)+1,0);
successCode=send(clientSocketDescriptor,response,strlen(response)+1,0);
if(successCode>0)
{
printf("Response sent\n");
}
else
{
printf("Unable to send response\n");
}
close(clientSocketDescriptor);
close(serverSocketDescriptor);
return 0;
}
