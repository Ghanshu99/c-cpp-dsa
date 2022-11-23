int main()
{
TMArrayList list1;
bool k;
for(int x=100;x<=123;x++)
{
list1.add(x,&k);
}
cout<<"size is :"<<list1.getSize()<<endl;
TMArrayList list2(list1);
for(int e=0;e<list2.getSize();e++)
{
cout<<list2.get(e,&k)<<" ";
}
cout<<endl;
TMArrayList list3;
for(int e=0;e<list3.getSize();e++)
{
cout<<list3.get(e,&k)<<" ";
}
return 0;
}