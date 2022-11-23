int main()
{
cout<<"TMForwardList Implementation"<<endl;
TMForwardList list1;
bool k;
for(int x=101;x<=110;x++)
{
list1.add(x,&k);
}
cout<<"size is"<<list1.getSize()<<endl;
for(int x=0;x<list1.getSize();x++)
{
cout<<list1.get(x,&k)<<" ";
}
cout<<"****************************"<<endl;
list1.update(2,5000,&k);
if(k)
{
cout<<"update successfull"<<endl;
}
else
{
cout<<"Unable to update"<<endl;
}
for(int x=0;x<list1.getSize();x++) cout<<list1.get(x,&k)<<endl;
cout<<"****************************"<<endl;
list1.insertAt(6,12345,&k);
if(k)
{
cout<<"Insertion successfull"<<endl;
}
else
{
cout<<"Unable to insert"<<endl;
}
for(int x=0;x<list1.getSize();x++) cout<<list1.get(x,&k)<<endl;
cout<<"****************************"<<endl;
list1.removeAt(1,&k);
if(k)
{
cout<<"Removal successfull"<<endl;
}
else
{
cout<<"Unable to remove"<<endl;
}
for(int x=0;x<list1.getSize();x++) cout<<list1.get(x,&k)<<endl;
cout<<"****************************"<<endl;
list1.getSize()<<endl;
list1.removeAll();
cout<<list1.getSize()<<endl;
return 0;
}