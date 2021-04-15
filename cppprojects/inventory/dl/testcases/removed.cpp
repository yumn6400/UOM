#include<dl/iuom>
#include<dl/uom>
#include<sqlite3.h>
#include<dl/iuomdao>
#include<dl/uomdao>
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
cout<<"Enter code:";
cin>>code;
UnitOfMeasurementDAO unitOfMeasurementDAO;
try
{
unitOfMeasurementDAO.remove(code);
cout<<"remove successfully"<<endl;
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}



return 0;
}