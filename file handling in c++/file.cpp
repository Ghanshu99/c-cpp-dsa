#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
using namespace std;
void addFriend()
{
char name[22],contactNumber[82];
cout<<"enter name :";
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
// scanf("%s",name);
int i;
for(i=0;name[i]!='\0';i++)
{
if(name[i]=='i')
{
cout<<"Name cannot contain ! symbol"<<endl;
return ;
}
}
cout<<"enter contact number :";
fgets(contactNumber,82,stdin);
fflush(stdin);
contactNumber[strlen(contactNumber)-1]='\0';
// scanf("%s",contactNumber);
for(i=0;contactNumber[i]!='\0';i++)
{
cout<<"contact number cannot contain ! symbol"<<endl;
return;
}
ofstream f("friends.ddd",ios::app);
i=0;
while(name[i]!='\0')
{
f<<name[i];
i++;
}
f<<'!';
i=0; 
while(contactNumber[i]!='\0')
{
f<<contactNumber[i];
i++;
}
f<<'!';
f.close();
cout<<"Friend added"<<endl;
}


void displayListOfFrieds()
{
ifstream k("friends.ddd");
if(k.fail())  //returns true if last operation failed
{
cout<<"No friends added"<<endl;
return;
}
char nm[21];
char cn[81];
int x;
char m;
while(1)
{
k>>m;
if(k.fail()) break;
nm[0]=m;
x=1;
while(1)
{
k>>m;
if(m=='!') break;
nm[x]=m;
x++;
}
nm[x]='\0';
x=0;
while(1)
{
k>>m;
if(m=='!') break;
cn[x]=m;
x++;
}
cn[x]='\0';
cout<<"Name :"<<nm<<", contact number"<<cn<<endl;
}
k.close();
}
int main()
{
int ch;
while(1)
{
cout<<"1.Add friend"<<endl;
cout<<"2.Display List of friends"<<endl;
cout<<"3.Exit"<<endl;
cout<<"Enter your choice :";
scanf("%d",&ch);
fflush(stdin);
if(ch==1) addFriend();
if(ch==2) displayListOfFrieds();
if(ch==3) break;
}
return 0;
}
