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
UnitOfMeasurementDAO unitOfMeasurementDAO;
abc::IUnitOfMeasurement *unitOfMeasurement;
try
{
int code;
cout<<"Enter code:";
cin>>code;
unitOfMeasurement=unitOfMeasurementDAO.getByCode(code);
cout<<unitOfMeasurement->getCode()<<","<<unitOfMeasurement->getTitle()<<endl;
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}


return 0;
}