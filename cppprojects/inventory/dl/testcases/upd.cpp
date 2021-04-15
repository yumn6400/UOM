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
int code;
string title;
cout<<"Enter code:";
cin>>code;
cout<<"Enter title:";
cin>>title;
UnitOfMeasurement *unitOfMeasurement;
unitOfMeasurement=new UnitOfMeasurement;
unitOfMeasurement->setCode(code);
unitOfMeasurement->setTitle(title.c_str());
UnitOfMeasurementDAO unitOfMeasurementDAO;
try
{
unitOfMeasurementDAO.update(unitOfMeasurement);
cout<<"update successfully"<<endl;
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}



return 0;
}