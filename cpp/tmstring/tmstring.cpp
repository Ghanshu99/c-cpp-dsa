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
TMString(const char *);
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
this->ptr=new char[this->size];
strcpy(this->ptr,ptr);
}
ostream & operator<<(ostream &out,TMString &tmString)
{
if(tmString.ptr==NULL) return out;
out<<tmString.ptr;
return out;
}
int main()
{
	TMString g="its really cool";
	cout<<g<<endl;
	return 0;
}

