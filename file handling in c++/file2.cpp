#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
class OutputFileStream
{
private:
FILE *f;
int mode;
int lastOperationFailed;
public:
const static int append=1;
const static int overwrite=2;
OutputFileStream()
{
this->lastOperationFailed=0;
this->f=NULL;
this->mode=-1;
}
OutputFileStream(const char *fileName,int mode)
{
this->lastOperationFailed=0;
this->f=NULL;
this->mode=-1;
this->open(fileName,mode);
}
void open(const char *fileName,int mode)
{
if(f!=NULL)
{
fclose(f);
this->f=NULL;
this->mode=-1;
}
this->lastOperationFailed=1;
if(fileName==NULL) return;
if(mode!=append && mode!=overwrite) return;
if(mode==append)
{
f=fopen(fileName,"a");
}else if(mode==overwrite)
{
f=fopen(fileName,"w");
}
if(f==NULL) return;
this->lastOperationFailed=0;
}
void close()
{
this->lastOperationFailed=0;
if(this->f==NULL) return;
fclose(this->f);
}
int fail()
{
return this->lastOperationFailed;
}
OutputFileStream & operator<<(char c)
{
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
fputc(c,this->f);
this->lastOperationFailed=0;
return *this;
}
};
class InputFileStream
{
private:
FILE *f;
int lastOperationFailed;
public:
InputFileStream()
{
this->f=NULL;
this->lastOperationFailed=0;
}
InputFileStream(const char *fileName)
{
this->f=NULL;
this->lastOperationFailed=0;
open(fileName);
}
void open(const char *fileName)
{
if(this->f!=NULL)
{
fclose(this->f);
this->lastOperationFailed=0;
}
this->lastOperationFailed=1;
if(fileName==NULL) return;
this->f=fopen(fileName,"r");
if(this->f==NULL) return;
this->lastOperationFailed=0;
}
int fail()
{
return this->lastOperationFailed;
}
InputFileStream & operator>>(char &c)
{
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
if(feof(this->f)) return *this;
c=fgetc(this->f);
if(feof(this->f)) return *this;
this->lastOperationFailed=0;
return *this;
}
void close()
{
this->lastOperationFailed=0;
if(this->f!=NULL) fclose(this->f);
}
};


void addFriend()
{
char name[22],contactNumber[82];
cout<<"Enter name :";
// fgets(name,22,stdin);
// fflush(stdin);
// name[strlen(name)-1]='\0';
scanf("%s",name);
int i;
for(i=0;name[i]!='\0';i++)
{
if(name[i]=='!')
{
cout<<"Name cannot contain ! symbol"<<endl;
return;
}
}
cout<<"Enter contact number :";
// fgets(contactNumber,82,stdin);
// fflush(stdin);
// contactNumber[strlen(contactNumber)-1]='\0';
scanf("%s",contactNumber);
for(i=0;contactNumber[i]!='\0';i++)
{
if(name[i]=='!')
{
cout<<"Name cannot contain ! symbol"<<endl;
return;
}
}
ofstream f("friends.ddd",ios::app);
i=0;
while(name[i]!='\0')
{
f<<name[i];
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
// if(ch==2) displayListOfFriends();
if(ch==3) break;
}
return 0;
}