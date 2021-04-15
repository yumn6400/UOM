#include<iostream>
#include<bl/iuom>
#include<bl/uom>
#include<common/stringutils>
#include<dl/iuom>
#include<dl/uom>
#include<dl/iuomdao>
#include<dl/uomdao>
#include<dl/daoexception>
#include<bl/blexception>
#include<map>
#include<bl/iuommanager>
#include<bl/uommanager>
#include<forward_list>
using namespace std;
using namespace inventory;
using namespace business_layer;
using namespace stringutils;
bool UnitOfMeasurementTitleComparator::operator()(string *left,string *right)
{
return compareStringIgnoreCase(left->c_str(),right->c_str())<0;
}
UnitOfMeasurementManager::DataModel UnitOfMeasurementManager::dataModel;
UnitOfMeasurementManager::DataModel::DataModel()
{
populateDataStructure();
}
UnitOfMeasurementManager::DataModel::~DataModel()
{
}
void UnitOfMeasurementManager::DataModel::populateDataStructure()
{
forward_list<inventory::data_layer::abc::IUnitOfMeasurement *> *dlUnitOfMeasurements;
inventory::data_layer::UnitOfMeasurementDAO unitOfMeasurementDAO;
try
{
dlUnitOfMeasurements=unitOfMeasurementDAO.getAll();
forward_list<inventory::data_layer::abc::IUnitOfMeasurement *>::iterator i;
int code;
string *title;
inventory::data_layer::abc::IUnitOfMeasurement *dlUnitOfMeasurement;
for(i=dlUnitOfMeasurements->begin();i!=dlUnitOfMeasurements->end();++i)
{
dlUnitOfMeasurement=*i;
code=dlUnitOfMeasurement->getCode();
title=new string(dlUnitOfMeasurement->getTitle());
_UnitOfMeasurement *blUnitOfMeasurement;
blUnitOfMeasurement=new _UnitOfMeasurement;
blUnitOfMeasurement->code=code;
blUnitOfMeasurement->title=title;
this->codeWiseMap.insert(pair<int,_UnitOfMeasurement *>(code,blUnitOfMeasurement));
this->titleWiseMap.insert(pair<string *,_UnitOfMeasurement *>(title ,blUnitOfMeasurement));
delete dlUnitOfMeasurement;
}
delete dlUnitOfMeasurements;
}catch(inventory::data_layer::DAOException &daoexception)
{
//no need
}
}
void UnitOfMeasurementManager::addUnitOfMeasurementManager(abc::IUnitOfMeasurement *unitOfMeasurement)throw(BLException)
{
BLException blexception;
if(unitOfMeasurement==NULL)
{
throw BLException("unit of measurement required ,null encountered");
}
int code=unitOfMeasurement->getCode();
string title=unitOfMeasurement->getTitle();
if(code!=0)
{
blexception.addPropertyException("code","code should be zero");
}
if(title.length()>50)
{
blexception.addPropertyException("title","Length of title should not be greater than 50");
}
if(blexception.hasExceptions())
{
throw blexception;
}
map<string *,_UnitOfMeasurement *,UnitOfMeasurementTitleComparator>::iterator i;
i=dataModel.titleWiseMap.find(&title);
if(i!=dataModel.titleWiseMap.end())
{
blexception.addPropertyException("title","given title exist");
throw blexception;
}
try
{
inventory::data_layer::abc::IUnitOfMeasurement * dlUnitOfMeasurement;
dlUnitOfMeasurement=new inventory::data_layer::UnitOfMeasurement;
dlUnitOfMeasurement->setCode(code);
dlUnitOfMeasurement->setTitle(title);
inventory::data_layer::UnitOfMeasurementDAO dlUnitOfMeasurementDAO;
dlUnitOfMeasurementDAO.add(dlUnitOfMeasurement);
dlUnitOfMeasurement=dlUnitOfMeasurementDAO.getByTitle(title);
unitOfMeasurement->setCode(dlUnitOfMeasurement->getCode());
code=dlUnitOfMeasurement->getCode();
delete dlUnitOfMeasurement;

string *t=new string(title);
_UnitOfMeasurement *blUnitOfMeasurement;
blUnitOfMeasurement=new _UnitOfMeasurement;
blUnitOfMeasurement->code=code;
blUnitOfMeasurement->title=t;
dataModel.codeWiseMap.insert(pair<int,_UnitOfMeasurement *>(code,blUnitOfMeasurement));
dataModel.titleWiseMap.insert(pair<string *,_UnitOfMeasurement *>(t,blUnitOfMeasurement));
}catch(inventory::data_layer::DAOException daoexception)
{
BLException blexception;
blexception.setGenericException(string(daoexception.what()));
throw blexception;
}
}
void UnitOfMeasurementManager::updateUnitOfMeasurementManager(abc::IUnitOfMeasurement *unitOfMeasurement)throw(BLException)
{
BLException blexception;
if(unitOfMeasurement==NULL)
{
throw BLException("unit of measurement required ,null encountered");
}
int code=unitOfMeasurement->getCode();
string vtitle=unitOfMeasurement->getTitle();
string title=trimmed(vtitle);
if(code<=0)
{
blexception.addPropertyException("code","code should be greater than 0");
}
if(title.length()>50)
{
blexception.addPropertyException("title","Length of title should not be greater than 50");
}
if(blexception.hasExceptions())
{
throw blexception;
}
map<int,_UnitOfMeasurement *>::iterator i;
i=dataModel.codeWiseMap.find(code);
if(i==dataModel.codeWiseMap.end())
{
blexception.addPropertyException("code","given code does not exist");
throw blexception;
}
map<string *,_UnitOfMeasurement *,UnitOfMeasurementTitleComparator>::iterator t;
t=dataModel.titleWiseMap.find(&title);
if(t!=dataModel.titleWiseMap.end()&&t->second->code!=code)
{
blexception.addPropertyException("title","given title exist");
throw blexception;
}
try
{
inventory::data_layer::abc::IUnitOfMeasurement * dlUnitOfMeasurement;
dlUnitOfMeasurement=new inventory::data_layer::UnitOfMeasurement;
dlUnitOfMeasurement->setCode(code);
dlUnitOfMeasurement->setTitle(title);
inventory::data_layer::UnitOfMeasurementDAO dlUnitOfMeasurementDAO;
dlUnitOfMeasurementDAO.update(dlUnitOfMeasurement);
unitOfMeasurement->setCode(dlUnitOfMeasurement->getCode());
delete dlUnitOfMeasurement;
string *t=new string(title);
_UnitOfMeasurement *blUnitOfMeasurement;
blUnitOfMeasurement=new _UnitOfMeasurement;
blUnitOfMeasurement->code=code;
blUnitOfMeasurement->title=t;
dataModel.codeWiseMap.erase(code);
string *Btitle=i->second->title;
dataModel.titleWiseMap.erase(Btitle);
dataModel.codeWiseMap.insert(pair<int,_UnitOfMeasurement *>(code,blUnitOfMeasurement));
dataModel.titleWiseMap.insert(pair<string *,_UnitOfMeasurement *>(t,blUnitOfMeasurement));
}catch(inventory::data_layer::DAOException daoexception)
{
BLException blexception;
blexception.setGenericException(string(daoexception.what()));
throw blexception;
}
}
void UnitOfMeasurementManager::removeUnitOfMeasurementManagerByCode(int code)throw(BLException)
{
BLException blexception;
if(code<=0)
{
blexception.addPropertyException("code","code should be greater than 0");
throw blexception;
}
map<int,_UnitOfMeasurement *>::iterator i;
i=dataModel.codeWiseMap.find(code);
if(i==dataModel.codeWiseMap.end())
{
blexception.addPropertyException("code","given code does not exist");
throw blexception;
}
try
{
string *title=i->second->title;
inventory::data_layer::UnitOfMeasurementDAO dlUnitOfMeasurementDAO;
dlUnitOfMeasurementDAO.remove(code);
dataModel.codeWiseMap.erase(code);
dataModel.titleWiseMap.erase(title);
}catch(inventory::data_layer::DAOException daoexception)
{
BLException blexception;
blexception.setGenericException(string(daoexception.what()));
throw blexception;
}
}
void UnitOfMeasurementManager::removeUnitOfMeasurementManagerByTitle(string &title)throw(BLException)
{
BLException blexception;
string vTitle=trimmed(title);
if(vTitle.length()==0)
{
blexception.addPropertyException("title","title does not exist");
}
if(vTitle.length()>50)
{
blexception.addPropertyException("title","Length of title should not be greater than 50");
}
if(blexception.hasExceptions())
{
throw blexception;
}
map<string *,_UnitOfMeasurement *,UnitOfMeasurementTitleComparator>::iterator i;
i=dataModel.titleWiseMap.find(&vTitle);
if(i==dataModel.titleWiseMap.end())
{
blexception.addPropertyException("title","given title does not exist");
throw blexception;
}
try
{
int code=i->second->code;
inventory::data_layer::UnitOfMeasurementDAO dlUnitOfMeasurementDAO;
dlUnitOfMeasurementDAO.remove(code);
dataModel.codeWiseMap.erase(code);
dataModel.titleWiseMap.erase(&vTitle);
}catch(inventory::data_layer::DAOException daoexception)
{
BLException blexception;
blexception.setGenericException(string(daoexception.what()));
throw blexception;
}
}
abc::IUnitOfMeasurement *UnitOfMeasurementManager::getUnitOfMeasurementByCode(int code)throw(BLException)
{
BLException blexception;
if(code<=0)
{
blexception.setGenericException("Invalid code");
throw blexception;
}
map<int ,_UnitOfMeasurement *>::iterator i;
i=dataModel.codeWiseMap.find(code);
if(i==dataModel.codeWiseMap.end())
{
blexception.setGenericException("code does not exist");
throw blexception;
}
_UnitOfMeasurement *blUnitOfMeasurement;
blUnitOfMeasurement=i->second;
abc::IUnitOfMeasurement *unitOfMeasurement;
unitOfMeasurement=new UnitOfMeasurement;
unitOfMeasurement->setCode(blUnitOfMeasurement->code);
unitOfMeasurement->setTitle(*(blUnitOfMeasurement->title));
return unitOfMeasurement;
}
abc::IUnitOfMeasurement *UnitOfMeasurementManager::getUnitOfMeasurementByTitle(string &title)throw(BLException)
{
BLException blexception;
string vTitle=trimmed(title);
if(vTitle.length()==0)
{
blexception.addPropertyException("title","title does not exist");
}
if(vTitle.length()>50)
{
blexception.addPropertyException("title","Length of title should not be greater than 50");
}
if(blexception.hasExceptions())
{
throw blexception;
}
map<string * ,_UnitOfMeasurement *,UnitOfMeasurementTitleComparator>::iterator i;
i=dataModel.titleWiseMap.find(&vTitle);
if(i==dataModel.titleWiseMap.end())
{
blexception.setGenericException("title does not exist");
throw blexception;
}
_UnitOfMeasurement *blUnitOfMeasurement;
blUnitOfMeasurement=i->second;
abc::IUnitOfMeasurement *unitOfMeasurement;
unitOfMeasurement=new UnitOfMeasurement;
unitOfMeasurement->setCode(blUnitOfMeasurement->code);
unitOfMeasurement->setTitle(*(blUnitOfMeasurement->title));
return unitOfMeasurement;
}
forward_list<abc::IUnitOfMeasurement *> *UnitOfMeasurementManager::getAllUnitOfMeasurement()throw(BLException)
{
map<string *,_UnitOfMeasurement *>::iterator i;
forward_list<abc::IUnitOfMeasurement *> *unitOfMeasurements;
unitOfMeasurements=new forward_list<abc::IUnitOfMeasurement *>;
forward_list<abc::IUnitOfMeasurement *>::iterator listi=unitOfMeasurements->before_begin();
_UnitOfMeasurement *unitOfMeasurement;
abc::IUnitOfMeasurement *blUnitOfMeasurement;
for(i=dataModel.titleWiseMap.begin();i!=dataModel.titleWiseMap.end();++i)
{
unitOfMeasurement=i->second;
blUnitOfMeasurement=new UnitOfMeasurement;
blUnitOfMeasurement->setCode(unitOfMeasurement->code);
blUnitOfMeasurement->setTitle(*(unitOfMeasurement->title));
listi=unitOfMeasurements->insert_after(listi,blUnitOfMeasurement);
}
return unitOfMeasurements;
}
int UnitOfMeasurementManager::unitOfMeasurementCodeExist(int code)throw(BLException)
{
BLException blexception;
map<int,_UnitOfMeasurement *>::iterator i;
i=dataModel.codeWiseMap.find(code);
if(i==dataModel.codeWiseMap.end())
{
return 0;
}
return 1;
}
int UnitOfMeasurementManager::unitOfMeasurementTitleExist(string &title)throw(BLException)
{
BLException blexception;
string vTitle=trimmed(title);
if(title.length()==0)
{
blexception.addPropertyException("title","title does not exist");
}
if(title.length()>50)
{
blexception.addPropertyException("title","Length of title should not be greater than 50");
}
if(blexception.hasExceptions())
{
throw blexception;
}
map<string *,_UnitOfMeasurement *,UnitOfMeasurementTitleComparator>::iterator i;
i=dataModel.titleWiseMap.find(&vTitle);
if(i!=dataModel.titleWiseMap.end())
{
return 1;
}
return 0;
}
int UnitOfMeasurementManager::getUnitOfMeasurementCount()throw(BLException)
{
inventory::data_layer::UnitOfMeasurementDAO dlUnitOfMeasurement;
return dlUnitOfMeasurement.getCount();
}