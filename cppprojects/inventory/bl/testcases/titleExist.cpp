#include<iostream>
#include<bl/uom>
#include<bl/uommanager>
#include<bl/blexception>
#include<forward_list>
using namespace std;
using namespace inventory;
using namespace business_layer;
int main()
{
UnitOfMeasurementManager manager;
try
{
string title;
int x;
cout<<"Enter a title:";
cin>>title;
x=manager.unitOfMeasurementTitleExist(title);
if(x==1)cout<<"title exist:Yes"<<endl;
else cout<<"title exist:No"<<endl;
}
catch(BLException blexception)
{
if(blexception.hasGenericException())
{
cout<<blexception.getGenericException()<<endl;
}
if(blexception.hasPropertyException("code"))
{
cout<<blexception.getPropertyException("code")<<endl;
}
if(blexception.hasPropertyException("title"))
{
cout<<blexception.getPropertyException("title")<<endl;
}
}
return 0;
}