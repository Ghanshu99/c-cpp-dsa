#include<iostream>
#include<map>
#include<utility>
using namespace std;
class Bulb
{
private:
int w;
Bulb(int w)
{
cout<<"Object created with wattage as"<<w<<endl;
this->w=w;
}
public:
~Bulb()
{
cout<<"Object with wattage as"<<w<<"is being destroyed"<<endl;
}
int getWattage()
{
return this->w;
}
void operator delete(void *ptr)
{
//do nothing
}
friend class BulbFactory;
};
class BulbFacotry
{
map<int,Bulb *> bulbs;
public:
Bulb *getBulb(int w)
{
if(w<0 || w>240) return NULL;
map<int,Bulb *>::iterator i;
i=bulbs.find(w);
Bulb *b;
if(i==bulbs.end())
{
b=new Bulb(w);
bulbs.insert(pair<int,Bulb *>(w,b));
}
else
{
b=i->second;
}
return b;
}
~BulbFacotry()
{
cout<<"Destructor got invoked"<<endl;
map<int,Bulb *>::iterator i;
for(i=bulbs.begin();i!=bulbs.end();i++)
{
delete (i->second);
}
}
};
int main()
{

}