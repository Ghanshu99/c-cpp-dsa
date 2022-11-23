#include<stdio.h>
#include<stdlib.h>
typedef struct __stack_node
{
int data;
struct __stack_node *next;
}stackNode;
typedef struct __stack
{
stackNode *top;
int size;
}Stack;
void initStack(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}
void push(Stack *stack,int data)
{
stackNode *t;
t=(stackNode *)malloc(sizeof(stackNode));
t->data=data;
t->next=stack->top;
stack->top=t;
stack->size++;
}
int pop(Stack *stack)
{
stackNode *t;
int data;
data=stack->top->data;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
free(t);
return data;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
Stack lbStack,ubStack;
int lb,ub,pp;
initStack(&lbStack);
initStack(&ubStack);
push(&lbStack,lowerBound);
push(&ubStack,upperBound);
while(!isEmpty(&lbStack))
{
lb=pop(&lbStack);
ub=pop(&ubStack);
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)
{
push(&lbStack,pp+1);
push(&ubStack,ub);
}
if(lb<pp-1)
{
push(&lbStack,lb);
push(&ubStack,pp-1);
}
}
}
int main()
{
int x[10],y;
for(y=0;y<=9;y++)
{
printf("enter a number :");
scanf("%d",&x[y]);
}
quickSort(x,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}