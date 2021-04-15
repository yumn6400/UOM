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
string title;
cout<<"Enter code:";
cin>>code;
cout<<"Enter title:";
cin>>title;
UnitOfMeasurement uom;
uom.setCode(code);
uom.setTitle(title);
UnitOfMeasurementManager manager;
try
{
manager.updateUnitOfMeasurementManager(&uom);
cout<<title <<" updated"<<endl;
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