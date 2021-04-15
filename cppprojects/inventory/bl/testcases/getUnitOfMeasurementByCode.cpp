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
int c;
cout<<"Enter code:";
cin>>c;
abc::IUnitOfMeasurement *unitOfMeasurement;
UnitOfMeasurementManager manager;
int code;
string title;
try
{
unitOfMeasurement=manager.getUnitOfMeasurementByCode(c);
code=unitOfMeasurement->getCode();
title=unitOfMeasurement->getTitle();
cout<<"code:"<<code<<"title:"<<title<<endl;
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