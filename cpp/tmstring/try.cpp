#include<iostream>
#include<string.h>
using namespace std;
class TMString
{
private:
char *ptr;
int size;
public:
TMString();
TMString(const char *ptr);
virtual ~TMString();
TMString & operator=(const TMString &other);
TMString & operator=(const char *ptr);
int operator>(const TMString &other);
int operator<(const TMString &other);
int operator==(const TMString &other);
int operator>=(const TMString &other);
int operator<=(const TMString &other);
int operator!=(const TMString &other);
friend ostream & operator<<(ostream &out,TMString &tmString);
};
TMString::TMString()
{
this->ptr=NULL;
this->size=0;
}
TMString::TMString(const char *ptr)
{
this->ptr=NULL;
if(ptr==NULL) return;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
}
TMString & TMString::operator=(const char *ptr)
{
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(ptr==NULL) return *this;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
return *this;
}
TMString & TMString::operator=(const TMString &other)
{
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(other.ptr==NULL) return *this;
this->size=strlen(other.ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,other.ptr);
// cout<<"value of this poiter :"<<*this<<endl;
return *this;
}



int TMString::operator>(const TMString &other)
{
if(this->ptr==NULL && other.ptr!=NULL) return 0;
if(this->ptr!=NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(strcmp(this->ptr,other.ptr)>0) return 1;
else return 0;
}

int TMString::operator<(const TMString &other)
{
if(this->ptr==NULL && other.ptr!=NULL) return 0;
if(this->ptr!=NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(strcmp(this->ptr,other.ptr)<0) return 1;
else return 0;
}

int TMString::operator==(const TMString &other)
{
if(this->ptr==NULL && other.ptr!=NULL) return 0;
if(this->ptr!=NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(strcmp(this->ptr,other.ptr)==0) return 1;
else return 0;
}


int TMString::operator>=(const TMString &other)
{
if(this->ptr==NULL && other.ptr!=NULL) return 0;
if(this->ptr!=NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(strcmp(this->ptr,other.ptr)>=0) return 1;
else return 0;
}

int TMString::operator<=(const TMString &other)
{
if(this->ptr==NULL && other.ptr!=NULL) return 0;
if(this->ptr!=NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(strcmp(this->ptr,other.ptr)<=0) return 1;
else return 0;
}
int TMString::operator!=(const TMString &other)
{
if(this->ptr==NULL && other.ptr!=NULL) return 0;
if(this->ptr!=NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(strcmp(this->ptr,other.ptr)!=0) return 1;
else return 0;
}






TMString::~TMString()
{
if(this->ptr) delete [] this->ptr;
}
ostream & operator<<(ostream &oo,TMString &tmString)
{
if(tmString.ptr==NULL) return oo; 
oo<<tmString.ptr;
return oo;
}
int main()
{
	// TMString g="cool";
	// cout<<g<<endl;
	// TMString m;
	// m="very Cool";
	// cout<<m<<endl;
	// TMString k;
	// k=m;
	// cout<<k<<endl;	
	// TMString g="Aham";
	// TMString k="Goa";
	TMString g,k;
	g="Goa";
	k="Goa";
	cout<<(g>k)<<endl;
	cout<<(g<k)<<endl;
	cout<<(g==k)<<endl;
	cout<<(g>=k)<<endl;
	cout<<(g<=k)<<endl;
	cout<<(g!=k)<<endl;
	return 0;
}

