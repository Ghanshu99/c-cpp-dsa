#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void addFriend()
{
char name[22],sNumber[52];
FILE *f;
int x;
printf("enter name :");
scanf("%s",name);
for(x=0;name[x]!='\0';x++) 
{
if(name[x]=='!')
{
printf("name cannot contain ! symbol\n");
return ;
}
}
printf("enter contact number :");
scanf("%s",sNumber);
for(x=0;sNumber[x]!='\0';x++)
{
if(sNumber[x]=='!')
{
printf("contact Number cannot contain ! symbol\n");
return ;
}
}
f=fopen("friends.ddd","a");
for(x=0;name[x]!='\0';x++) fputc(name[x],f);
fputc('!',f);
for(x=0;sNumber[x]!='\0';x++) fputc(sNumber[x],f);
fputc('!',f);
fclose(f);
printf("friend added \n");
}

void displayListOfFriends()
{
char nm[21],cn[51];
FILE *k;
char g;
int x;
k=fopen("friends.ddd","r");
if(k==NULL)
{
printf("no friends are added\n");
return ;
}
while(1)
{
g=fgetc(k);
if(feof(k)) break;
nm[0]=g;
x=1;
while(1)
{
g=fgetc(k);
if(g=='!') break;
nm[x]=g;
x++;
}
nm[x]='\0';
x=0;
while(1)
{
g=fgetc(k);
if(g=='!') break;
cn[x]=g;
x++;
}
cn[x]='\0';
printf("Name :%s,contact Number :%s \n" ,nm,cn);
}
fclose(k);
}

int main()
{
int ch;
while(1)
{
printf("1.add friend \n");
printf("2.display list of friends \n");
printf("3.exit \n");
printf("enter your choice ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addFriend();
if(ch==2) displayListOfFriends();
if(ch==3) break;
}
return 0;
}
