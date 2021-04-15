#include<dl/iuom>
#include<dl/uom>
#include<sqlite3.h>
#include<dl/iuomdao>
#include<dl/uomdao>
#include<iostream>
using namespace std;
using namespace inventory;
using namespace data_layer;
int main()
{
int code;
cout<<"Enter code:";
cin>>code;
UnitOfMeasurementDAO unitOfMeasurementDAO;
try
{
int e=unitOfMeasurementDAO.codeExist(code);
if(e==1)cout<<"exist";
else cout<<"not exist";
}catch(DAOException daoexception)
{
cout<<daoexception.what()<<endl;
}


return 0;
}