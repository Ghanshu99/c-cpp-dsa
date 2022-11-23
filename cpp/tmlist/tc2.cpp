int main()
{
TMArryaList list1(6000);
bool k;
for(int x=100;x<=123;x++)
{
list1.add(x,&k);
}
cout<<"size is"<<list1.getSize()<<endl;
for(int e=0;e<list1.getSize();e++)
{
cout<<list1.get(e,&k)<<" ";
}
cout<<endl;
list1.update(102,5000,&k);
if(k) cout<<"data updated at index 102"<<endl;
else cout<<"unable to update data at index 102"<<endl;
list1.update(3,3030,&k);
if(k) cout<<"data updated at index 3"<<endl;
else cout<<"unable to update data at index 3"<<endl;
for(int e=0;e<list1.getSize();e++)
{
cout<<list1.get(e,&k)<<" ";
}
cout<<endl;
list1.insertAt(8,6060,&k);
if(k) cout<<"data inserted at index 8"<<endl;
else cout<<"unable to insert data at index 8<<endl";
for(int e=0;e<list1.getSize();e++)
{
	cout<<list1.get(e,&k)<<" ";
}
cout<<endl;
int u=list1.removeAt(3,&k);
if(k) cout<<u<<<"removed from index 3"<<endl;
else cout<<"unable to remove form index 3"<<endl;
for(int e=0;e<list1.getSize();e++)
{
cout<<list1.get(e,&k)<<" ";
}
cout<<endl;
return 0;
}