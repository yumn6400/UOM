#include<dl/iuom>
#include<dl/uom>
#include<dl/iuomdao>
#include<dl/uomdao>
#include<sqlite3.h>
#include<iostream>
using namespace std;
using namespace inventory;
using namespace data_layer;
int main()
{
string title;
UnitOfMeasurementDAO unitOfMeasurementDAO;
cout<<"Enter title:";
cin>>title;
try
{
int e=unitOfMeasurementDAO.titleExist(string(title));
if(e==1)cout<<"exist";
else cout<<"not exist";
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}


return 0;
}