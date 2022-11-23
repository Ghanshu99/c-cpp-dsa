int main()
{
bool succ;
TMArrayList list1;
for(int x=50;x<=4023;x++)
{
	list1.add(x,&succ);
}
cout<<"size is"<<list1.getSize()<<endl;
for(int e=0;e<list1.getSize();e++)
{
	cout<<list1.get(e,&succ)<<" ";
}
return 0;
}