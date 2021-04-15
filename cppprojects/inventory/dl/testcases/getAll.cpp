#include<dl/iuom>
#include<dl/uom>
#include<dl/iuomdao>
#include<dl/uomdao>
#include<sqlite3.h>
#include<common/stringutils>
#include<forward_list>
#include<iostream>
using namespace std;
using namespace inventory;
using namespace data_layer;
using namespace stringutils;
int main()
{
abc::IUnitOfMeasurement *unitOfMeasurement;
UnitOfMeasurementDAO unitOfMeasurementDAO;
forward_list<abc::IUnitOfMeasurement *>*list;
forward_list<abc::IUnitOfMeasurement *>::iterator i;
try
{
list=unitOfMeasurementDAO.getAll();
for(i=list->begin();i!=list->end();++i)
{
unitOfMeasurement=*i;
cout<<unitOfMeasurement->getCode()<<","<<unitOfMeasurement->getTitle()<<endl;
}
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}
return 0;
}