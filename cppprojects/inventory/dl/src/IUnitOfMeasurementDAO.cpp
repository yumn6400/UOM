#include<dl/iuomdao>
#include<sqlite3.h>
#include<string.h>
#include<stdlib.h>
using namespace inventory;
using namespace data_layer;
const char *abc::IUnitOfMeasurementDAO::FILE_NAME="uomdb.db";
int abc::IUnitOfMeasurementDAO::getAllData(void *ptr,int columnCount,char **dataPtr,char **columnNamePtr)
{
forward_list<abc::IUnitOfMeasurement *> *list=(forward_list<abc::IUnitOfMeasurement *> *)ptr;
abc::IUnitOfMeasurement *uom=new UnitOfMeasurement;
forward_list<abc::IUnitOfMeasurement *>::iterator i=list->before_begin();
int code;
string title;
code=atoi(dataPtr[0]);
title=dataPtr[1];
uom->setCode(code);
uom->setTitle(title);
list->insert_after(i,uom);
return 0;
}
int abc::IUnitOfMeasurementDAO::dataCapture(void *ptr,int columnCount,char **dataPtr,char **columnNamePtr)
{
abc::IUnitOfMeasurement *uom=(abc::IUnitOfMeasurement *)ptr;
int code;
string title;
code=atoi(dataPtr[0]);
title=dataPtr[1];
uom->setCode(code);
uom->setTitle(title);
return 0;
}
int abc::IUnitOfMeasurementDAO::rowHandler(void *ptr,int columnCount,char **dataPtr,char **columnNamePtr)
{
int *count=(int *)ptr;
*count=*count+1;
return 0;
}