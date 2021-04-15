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
UnitOfMeasurement uom;
UnitOfMeasurementManager manager;
try
{
forward_list<abc::IUnitOfMeasurement *> *list;
list=manager.getAllUnitOfMeasurement();
forward_list<abc::IUnitOfMeasurement *>::iterator i;
abc::IUnitOfMeasurement *unitOfMeasurement;
for(i=list->begin();i!=list->end();++i)
{
unitOfMeasurement=*i;
cout<<unitOfMeasurement->getCode()<<","<<unitOfMeasurement->getTitle()<<endl;
}
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