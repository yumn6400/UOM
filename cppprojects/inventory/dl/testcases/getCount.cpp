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
try
{
cout<<"unit of measurement get count be:"<<unitOfMeasurementDAO.getCount()<<endl;
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}


return 0;
}