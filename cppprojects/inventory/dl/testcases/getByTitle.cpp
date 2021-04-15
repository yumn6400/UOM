#include<dl/iuom>
#include<dl/uom>
#include<dl/iuomdao>
#include<dl/uomdao>
#include<iostream>
using namespace std;
using namespace inventory;
using namespace data_layer;
int main()
{
string title;
UnitOfMeasurementDAO unitOfMeasurementDAO;
abc::IUnitOfMeasurement *unitOfMeasurement;
cout<<"Enter string:";
cin>>title;
try
{
unitOfMeasurement=unitOfMeasurementDAO.getByTitle(title);
cout<<unitOfMeasurement->getCode()<<","<<unitOfMeasurement->getTitle()<<endl;
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}


return 0;
}