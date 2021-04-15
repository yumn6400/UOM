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
int code;
cout<<"Enter code:";
cin>>code;
UnitOfMeasurementManager manager;
try
{
manager.removeUnitOfMeasurementManagerByCode(code);
cout<<"Removed successfully";
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