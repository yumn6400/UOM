#include<dl/iuom>
#include<dl/uom>
#include<dl/iuomdao>
#include<dl/uomdao>
#include<forward_list>
#include<iostream>
#include<sqlite3.h>
using namespace std;
using namespace inventory;
using namespace data_layer;
int main()
{
string title;
cout<<"Enter title:";
cin>>title;
UnitOfMeasurement unitOfMeasurement;
unitOfMeasurement.setTitle(string(title));
UnitOfMeasurementDAO unitOfMeasurementDAO;
try
{
unitOfMeasurementDAO.add(&unitOfMeasurement);
cout<<unitOfMeasurement.getTitle()<<" added successfully"<<endl;
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}



return 0;
}