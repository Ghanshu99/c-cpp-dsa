#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void linearSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,w,ep1,ep2;
void *a,*b,*c;
c=(void *)malloc(es);
ep1=cs-2;
ep2=cs-1;
for(e=0;e<=ep1;e++)
{
for(f=e+1;f<=ep2;f++)
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
}
}
free(c);
}
int myComparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
int main()
{
int *x,y,req;
printf("enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
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
linearSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
