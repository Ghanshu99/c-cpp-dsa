#include<iostream>
using namespace std;
class aaa
{
int fhaltu;
int x[10];
public:
/*void setData(int i,int data)
{
x[i]=data;
}*/
int & operator[](int index)
{
if(index<0 || index>9) return fhaltu;
return x[index];
}
};
int main()
{
aaa a;
a[0]=10;
a[0]=11;
a[1]=23;
a[2]=434;
a[4444444]=77;
cout<<a[0]<<endl;
cout<<a[1]<<endl;
cout<<a[2]<<endl;
cout<<a[444444]<<endl;
cout<<a[34566]<<endl;
return 0;
}