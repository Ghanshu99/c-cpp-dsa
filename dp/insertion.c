#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void insertionSort(void *x,int cs,int es,int (*p2f)(void *,void *))
{
int y,z,ep;
void *block;
block=(void *)malloc(es);
ep=cs-1;
for(y=1;y<=ep;y++)
{
//num=x[y];	

//for(z=y-1;z>=0 && x[z]>num;z--)
for(memcpy(block,(void *)(x+(y*es)),es),z=y-1;z>=0 && p2f(x+(z*es),block)>0;z--) 
{
//x[z+1]=x[z];
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
}
memcpy(x+((z+1)*es),(const void *)block,es);
//x[z+1]=num;
}
free(block);
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
printf("Unable to allocate memory to %d numbers",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("enter a number :");
scanf("%d",&x[y]);
}
insertionSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}