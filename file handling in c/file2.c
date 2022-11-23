#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void addFriend()
{
char name[22],contactNumber[52];
FILE *f;
printf("enter name :");
scanf("%s",name);
// fgets(name,22,stdin);
// fflush(stdin);
// name[strlen(name)-1]='\0';
printf("enter contact number :");
scanf("%s",contactNumber);
// fgets(contactNumber,52,stdin);
// fflush(stdin);
// contactNumber[strlen(contactNumber)-1]='\0';
f=fopen("friends.xyz","w");
fputs(name,f);
fputc('\n',f);
fputs(contactNumber,f);
fputc('\n',f);
fclose(f);
printf("Friend added\n");
}
void displayListOfFriends()
{
FILE *k;
char name[22],contactNumber[52];
k=fopen("friends.xyz","r");
if(k==NULL)
{
printf("no friends added\n");
return ;
}
while(1)
{
fgets(name,22,k);
if(feof(k)) break;
name[strlen(name)-1]='\0';
fgets(contactNumber,22,k);
contactNumber[strlen(contactNumber)-1]='\0';
printf("Name :%s,contactNumber :%s\n",name,contactNumber);
}
fclose(k);
}
int main()
{
int ch;
while(1)
{
printf("1.add friend\n");
printf("2.display List Of Friends\n");
printf("3.exit\n");
printf("enter your choice :");
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addFriend();
if(ch==2) displayListOfFriends();
if(ch==3) break;	
}
return 0; 
}