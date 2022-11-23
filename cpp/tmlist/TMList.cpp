#include<iostream>
#define bool int 
#define true 1
#define True 1
#define TRUE 1
#define false 0
#define False 0
#define FALSE 0
using namespace std;
class TMList
{
virtual void add(int data,bool *success)=0;
virtual int get(int index,bool *success) const=0;
virtual int getSize()=0;
virtual void insertAt(int index,int data,bool *success)=0;
virtual int removeAt(int index,bool *success)=0;
virtual void update(int index,int data,bool *success)=0;
virtual void removeAll()=0;
virtual void clear()=0;  
};


class TMArrayList:public TMList
{
private:
	char allocationFlag; //for handling issue related to + operation
	int **ptr;
	int capacity;
	int size;
	bool addRow();
public:
TMArrayList();
TMArrayList(int bufferSize);
TMArrayList(const TMArrayList &other);   
virtual ~TMArrayList();
TMArrayList & operator=(const TMArrayList &other);
TMArrayList operator+(const TMArrayList &other);
void operator+=(const TMArrayList &other);
void add(int data,bool *success);
int get(int index,bool *success) const;
int getSize();
void insertAt(int index,int data,bool *success);
int removeAt(int index,bool *success);
void update(int index,int data,bool *success);
void removeAll();
void clear(); 
};


bool TMArrayList::addRow()
{
	if(capacity%100==0)
	{
		int numberOfPointers;
		numberOfPointers=this->capacity/10;
		int **tmp=new int *[numberOfPointers+10];
		if(tmp==NULL) return false;
		for(int e=0;e<numberOfPointers;e++) tmp[e]=this->ptr[e];
		delete [] this->ptr;
		this->ptr=tmp;
	}
int i=this->capacity/10;
this->ptr[i]=new int[10];
if(this->ptr[i]==NULL) return false;
this->capacity=this->capacity+10;
return true;
}
TMArrayList::TMArrayList()
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->capacity=10;
this->size=0;
this->allocationFlag=0; //for handling issue related to + operation
}


TMArrayList::TMArrayList(int bufferSize)
{
this->allocationFlag=0; //for handling issue related to + operation
if(bufferSize<=0)
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->capacity=10;
this->size=0;
}
else
{
int rows;
int numberOfPointers;
rows=bufferSize/10;
if(bufferSize%10!=0) rows++;
numberOfPointers=rows+(10-(rows%10));
this->ptr=new int *[numberOfPointers];
for(int e=0;e<rows;e++) this->ptr[e]=new int [10];
this->capacity=rows*10;
this->size=0;
}
}

TMArrayList::TMArrayList(const TMArrayList &other)
{
this->allocationFlag=0; //for handling issue related to + operation
int bufferSize=other.size;
if(bufferSize<=0)
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->capacity=10;
this->size=0;
}
else
{
int rows;
int numberOfPointers;
rows=bufferSize/10;
if(bufferSize%10!=0) rows++;
numberOfPointers=rows+(10-(rows%10));
this->ptr=new int *[numberOfPointers];
for(int e=0;e<rows;e++) this->ptr[e]=new int [10];
this->capacity=rows*10;
this->size=0;
}
int succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
} 
}


TMArrayList::~TMArrayList()
{
if(this->allocationFlag==0)  //for handling issue related to + operation
{
int rows=this->capacity/10;
int j;
for(j=0;j<rows;j++)
{
delete [] this->ptr[j];
}
delete []this->ptr;
}
}

TMArrayList & TMArrayList::operator=(const TMArrayList &other)
{
if(other.allocationFlag==0)
{
this->size=0;
int succ;
for(int e=0;e<other.size;e++) this->add(other.get(e,&succ),&succ);
return *this;
}
else 
{
int rows=this->capacity/10;
int j;
for(j=0;j<rows;j++)
{
delete [] this->ptr[j];
}
delete []this->ptr;
this->ptr=other.ptr;
this->capacity=other.capacity;
this->size=other.size;
}
return *this;
}



void TMArrayList::operator+=(const TMArrayList &other)
{
int succ;
for(int e=0;e<other.size;e++) this->add(other.get(e,&succ),&succ);
}


TMArrayList TMArrayList::operator+(const TMArrayList &other)
{
TMArrayList k;
int succ;
for(int e=0;e<this->size;e++) k.add(this->get(e,&succ),&succ);
for(int e=0;e<other.size;e++) k.add(other.get(e,&succ),&succ);
return k;
}


void TMArrayList::add(int data,bool *success)
{
if(success) *success=false;
if(this->size==this->capacity) if(!addRow()) return;
int rowIndex,columnIndex;
rowIndex=this->size/10;
columnIndex=this->size%10;
this->ptr[rowIndex][columnIndex]=data;
this->size++;
if(success) *success=true;
}
int TMArrayList::get(int index,bool *success) const
{
if(success) *success=false;
if(index<0 || index>=this->size) return 0;
int rowIndex=index/10;
int columnIndex=index%10;
if(success) *success=true;
return ptr[rowIndex][columnIndex];
}


int TMArrayList::getSize()
{
	return this->size;
}
void TMArrayList::insertAt(int index,int data,bool *success)
{
if(success)*success=false;
if(index<0 || index>this->size) return;
if(index==this->size)
{
this->add(data,success);
return;
}
bool succ;
int k=this->get(this->size-1,&succ);
this->add(k,&succ);
if(succ==false) return;
int j;
j=this->size-3;
while(j>=index)
{
this->update(j+1,this->get(j,&succ),&succ);
j--;
}
this->update(index,data,&succ);
if(success) *success=true;
}
int TMArrayList::removeAt(int index,int *success)
{
if(success)*success=false;
if(index<0 || index>=size) return 0;
bool succ;
int data=this->get(index,&succ);
int j;
int ep=this->size-2;
j=index;
while(j<=ep)
{
this->update(j,this->get(j+1,&succ),&succ);
j++;
}
this->size--;
if(success) *success=true;
return data;
}
void TMArrayList::update(int index,int data,int *success)
{
if(success) *success=false;
if(index<0 || index>=size) return;
int rowIndex=index/10;
int columnIndex=index%10;
this->ptr[rowIndex][columnIndex]=data;
if(success) *success=true;
}
void TMArrayList::removeAll()
{
this->size=0;
}
void TMArrayList::clear()
{
this->size=0;
}


int main()
{
TMArrayList list1;
bool k;
for(int x=100;x<=123;x++)
{
list1.add(x,&k);
}
cout<<"size is"<<list1.getSize()<<endl;
cout<<"contents of list1"<<endl;
for(int x=0;x<list1.getSize();x++) cout<<list1.get(x,&k)<<" ";
cout<<"******************************"<<endl;
TMArrayList list2;
for(int u=908;u<=1034;u++) list2.add(u,&k);
cout<<"size is"<<list2.getSize()<<endl;
cout<<"contents of list2"<<endl;
for(int x=0;x<list2.getSize();x++) cout<<list2.get(x,&k)<<" ";
cout<<"now creating list3 and assigning list1+list2 to it"<<endl;
TMArrayList list3;
list3=list1+list2;
cout<<"after list3=list1+list2"<<endl;
cout<<"size of list3 is"<<list3.getSize()<<endl;
cout<<"contents of list3"<<endl;
for(int x=0;x<list3.getSize();x++) cout<<list3.get(x,&k)<<" ";
return 0;
}

