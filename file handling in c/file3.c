#include<stdio.h>
#include<string.h>
int main()
{
int rollNumber;
char name[22];
int std;
char sec;
FILE *f;
rollNumber=101;
strcpy(name,"Suresh Raina");
std=1;
sec='A';
f=fopen("lost.boy","w");
fprintf(f,"%d %s\n%d %c",rollNumber,name,std,sec);
rollNumber=102;
strcpy(name,"Ramesh Joshi");
std=2;
sec='c';
fprintf(f,"%d %s\n%d %c",rollNumber,name,std,sec);
fclose(f);
return 0;
}