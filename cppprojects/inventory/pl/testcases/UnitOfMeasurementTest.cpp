#include<iostream>
#include<bl/iuom>
#include<bl/uom>
#include<bl/iuommanager>
#include<bl/uommanager>
#include<forward_list>
using namespace std;
using namespace inventory;
using namespace business_layer;
int main()
{
int ch;
while(1)
{
cout<<"------------------------------------------------------------------------------";
cout<<"UNIT OF MEASUREMENT MODULE:"<<endl;
cout<<"------------------------------------------------------------------------------";
cout<<"1.Add"<<endl;
cout<<"2.Update"<<endl;
cout<<"3.Remove by code"<<endl;
cout<<"4.Remove by title"<<endl;
cout<<"5.Get by code"<<endl;
cout<<"6.Get by title"<<endl;
cout<<"7.Get all "<<endl;
cout<<"8.Code exist(Yes/No)"<<endl;
cout<<"9.Title exist(Yes/No)"<<endl;
cout<<"10.Get count"<<endl;
cout<<"11.Exit"<<endl;
cout<<"------------------------------------------------------------------------------";
cout<<"Enter your choice:";
cin>>ch;
if(ch==1)
{
string title;
cout<<"Enter title:";
cin>>title;
UnitOfMeasurement uom;
uom.setCode(0);
uom.setTitle(title);
UnitOfMeasurementManager manager;
try
{
manager.addUnitOfMeasurementManager(&uom);
cout<<title<<" added"<<endl;
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
}
else if(ch==2)
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
}
else if(ch==3)
{
int code;
cout<<"Enter code:";
cin>>code;
UnitOfMeasurementManager manager;
try
{
manager.removeUnitOfMeasurementManagerByCode(code);
cout<<"Removed successfully"<<endl;
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
}
else if(ch==4)
{
string title;
cout<<"Enter title:";
cin>>title;
UnitOfMeasurementManager manager;
try
{
manager.removeUnitOfMeasurementManagerByTitle(title);
cout<<"Removed successfully"<<endl;
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
}
else if(ch==5)
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
cout<<"code:"<<code<<", title:"<<title<<endl;
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
}
else if(ch==6)
{
string vTitle;
cout<<"Enter title:";
cin>>vTitle;
abc::IUnitOfMeasurement *unitOfMeasurement;
UnitOfMeasurementManager manager;
int code;
string title;
try
{
unitOfMeasurement=manager.getUnitOfMeasurementByTitle(vTitle);
code=unitOfMeasurement->getCode();
title=unitOfMeasurement->getTitle();
cout<<"code:"<<code<<", title:"<<title<<endl;
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
}

else if(ch==7)
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
}
else if(ch==8)
{
UnitOfMeasurementManager manager;
try
{
int x;
cout<<"Enter a number:";
cin>>x;
x=manager.unitOfMeasurementCodeExist(x);
if(x==1)cout<<"code exist:Yes"<<endl;
else cout<<"code exist:No"<<endl;
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
}
else if(ch==9)
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
}
else if(ch==10)
{
UnitOfMeasurementManager manager;
try
{
cout<<"count:"<<manager.getUnitOfMeasurementCount()<<endl;
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
}
else if(ch==11)
{
break;
}
else
{
cout<<"Invalid code"<<endl;
continue;
}
}
return 0;
}