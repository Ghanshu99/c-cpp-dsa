#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void bubbleSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
e++;
f++;
}
m--;
}
free(c);
}
struct Student
{
int rollNumber;
char name[21];
};
int studentComparator(void *left,void *right)
{
struct Student *s1,*s2;
s1=(struct Student *)left;
s2=(struct Student *)right;
//return s1->rollNumber-s2->rollNumber;
return strcmp(s1->name,s2->name);
}
int main()
{
int req,y;
struct Student *s,*j;
printf("enter requirement :");
scanf("%d",&req);
if(req<=0) 
{
printf("Invalid requirement\n");
return 0;
}
s=(struct Student *)malloc(sizeof(struct Student)*req);
j=s;
for(y=0;y<req;y++)
{
printf("enter your rollNumber :");
scanf("%d",&(j->rollNumber));
printf("enter your name :");
scanf("%s",j->name);
j++;
}
for(y=0;y<req;y++)
{
printf("%u\n",sizeof(j->rollNumber));
printf("%u\n",sizeof(j->name));
printf("%u\n",sizeof(j));
}
bubbleSort(s,req,sizeof(struct Student),studentComparator);
for(y=0;y<req;y++)
{
printf("Roll number %d ,Name %s\n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}
/*
int myComparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
int main()
{
int *x,req,y;
printf("enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement \n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("enter a number :");
scanf("%d",&x[y]);
}
bubbleSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
*/