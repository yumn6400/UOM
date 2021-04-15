#include<iostream>
#include<sqlite3.h>
#include<dl/iuom>
#include<dl/uom>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<common/stringutils>
#include<dl/daoexception>
#include<forward_list>
#include<dl/iuomdao>
#include<dl/uomdao>
using namespace inventory;
using namespace data_layer;
using namespace std;
using namespace stringutils;
void UnitOfMeasurementDAO::add(abc::IUnitOfMeasurement *unitOfMeasurement)throw(DAOException)
{
const string vtitle=unitOfMeasurement->getTitle();
string title=trimmed(vtitle);
int code=unitOfMeasurement->getCode();
if(vtitle.length()==0)
{
throw DAOException("title required,length is zero");
}
if(vtitle.length()>50)
{
throw DAOException("title length should not be greater than 50");
}
sqlite3 *db;
int result;
char sql[1001];
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sprintf(sql,"create table uom(code integer primary key AUTOINCREMENT,title string COLLATE NOCASE unique);");
sqlite3_exec(db,sql,0,0,&errorMessage);
sprintf(sql,"insert into uom(title)values('%s');",title.c_str());
result=sqlite3_exec(db,sql,0,0,&errorMessage);
if(result!=SQLITE_OK)
{
sprintf(sql,"Unable to insert records,reason %s\n",sqlite3_errmsg(db));
sqlite3_free(errorMessage);
sqlite3_close(db);
throw DAOException(sql);
}
sqlite3_close(db);
}
void UnitOfMeasurementDAO::update(abc::IUnitOfMeasurement *unitOfMeasurement)throw(DAOException)
{
const string vtitle=unitOfMeasurement->getTitle();
string title=trimmed(vtitle);
int code=unitOfMeasurement->getCode();
if(vtitle.length()==0)
{
throw DAOException("title required,length is zero");
}
if(vtitle.length()>50)
{
throw DAOException("title length should not be greater than 50");
}
sqlite3 *db;
int result;
char sql[1001];
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sprintf(sql,"update uom set title='%s' where code=%d;",title.c_str(),code);
result=sqlite3_exec(db,sql,0,0,&errorMessage);
if(result!=SQLITE_OK)
{
sprintf(sql,"Unable to update records,reason %s\n",sqlite3_errmsg(db));
sqlite3_free(errorMessage);
sqlite3_close(db);
throw DAOException(sql);
}
sqlite3_close(db);
}
void UnitOfMeasurementDAO::remove(int code)throw(DAOException)
{
if(code<=0)
{
throw DAOException("code should be greater than 0");
}
sqlite3 *db;
int result;
char sql[1001];
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sprintf(sql,"delete from uom where code=%d;",code);
result=sqlite3_exec(db,sql,0,0,&errorMessage);
if(result!=SQLITE_OK)
{
sprintf(sql,"Unable to delete records,reason %s\n",sqlite3_errmsg(db));
sqlite3_free(errorMessage);
sqlite3_close(db);
throw DAOException(sql);
}
sqlite3_close(db);
}
abc::IUnitOfMeasurement *UnitOfMeasurementDAO::getByCode(int code)throw(DAOException)
{
abc::IUnitOfMeasurement *unitOfMeasurement;
unitOfMeasurement=new UnitOfMeasurement;
if(code<=0)
{
throw DAOException("code should be greater than 0");
}
sqlite3 *db;
int result;
char sql[1001];
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sprintf(sql,"select * from uom where code =%d;",code);
result=sqlite3_exec(db,sql,dataCapture,(void *)unitOfMeasurement,&errorMessage);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"can not find ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sqlite3_close(db);
if(unitOfMeasurement->getCode()==0)
{
throw DAOException("given code does not exist");
}
return unitOfMeasurement;
}
abc::IUnitOfMeasurement *UnitOfMeasurementDAO::getByTitle(string title)throw(DAOException)
{
const string vTitle=trimmed(title);
if(vTitle.length()==0)
{
throw DAOException("title does not exist");
}
if(vTitle.length()>50)
{
throw DAOException("title does not exist");
}
abc::IUnitOfMeasurement *unitOfMeasurement;
unitOfMeasurement=new UnitOfMeasurement;
sqlite3 *db;
int result;
char sql[1001];
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sprintf(sql,"select * from uom where title ='%s';",vTitle.c_str());
result=sqlite3_exec(db,sql,dataCapture,(void *)unitOfMeasurement,&errorMessage);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"can not find ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sqlite3_close(db);
if(unitOfMeasurement->getTitle()=="")
{
throw DAOException("given title does not exist");
}
return unitOfMeasurement;
}
int UnitOfMeasurementDAO::getCount()throw(DAOException)
{
sqlite3 *db;
int result;
char sql[1001];
int output=0;
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
result=sqlite3_exec(db,"select * from uom",rowHandler,(void *)&output,&errorMessage);
sqlite3_close(db);
return output;
}
forward_list<abc::IUnitOfMeasurement *> *UnitOfMeasurementDAO::getAll()throw(DAOException)
{
forward_list<abc::IUnitOfMeasurement *> *list;
list=new forward_list<abc::IUnitOfMeasurement *>;
sqlite3 *db;
int result;
char sql[1001];
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
result=sqlite3_exec(db,"select * from uom;",getAllData,(void *)list,&errorMessage);
if(result!=SQLITE_OK)
{
sprintf(sql,"Unable to insert records,reason %s\n",sqlite3_errmsg(db));
sqlite3_free(errorMessage);
sqlite3_close(db);
throw DAOException(sql);
}
sqlite3_close(db);
return list;
}
int UnitOfMeasurementDAO::codeExist(int code)throw(DAOException)
{
if(code<=0)
{
throw DAOException("code should be greater than 0");
}
sqlite3 *db;
int result;
int output=0;
char sql[1001];
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sprintf(sql,"select * from uom where code =%d;",code);
result=sqlite3_exec(db,sql,rowHandler,&output,&errorMessage);
sqlite3_close(db);
if(output==1)return 1;
else return 0;
}
int UnitOfMeasurementDAO::titleExist(string title)throw(DAOException)
{
const string vtitle=trimmed(title);
if(vtitle.length()==0)
{
throw DAOException("title does not exist");
}
if(vtitle.length()>50)
{
throw DAOException("title does not exist");
}
sqlite3 *db;
int result;
int output=0;
char sql[1001];
char *errorMessage;
result=sqlite3_open("uom.db",&db);
if(result!=SQLITE_OK)
{
sqlite3_close(db);
sprintf(sql,"Unable to connect to uom.db ,reason %s\n",sqlite3_errmsg(db));
throw DAOException(sql); 
}
sprintf(sql,"select * from uom where title='%s';",vtitle.c_str());
result=sqlite3_exec(db,sql,rowHandler,(void *)&output,&errorMessage);
sqlite3_close(db);
if(output==0)return 0;
else return 1;
}