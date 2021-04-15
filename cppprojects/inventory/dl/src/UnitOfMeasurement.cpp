#include<iostream>
#include<dl/iuom>
#include<dl/uom>
using namespace std;
using namespace inventory;
using namespace data_layer;
UnitOfMeasurement::UnitOfMeasurement()
{
this->code=0;
this->title="";
}
UnitOfMeasurement::UnitOfMeasurement(int code,string title)
{
this->code=code;
this->title=title;
}
UnitOfMeasurement::UnitOfMeasurement(const UnitOfMeasurement &other)
{
this->code=other.code;
this->title=other.title;
}
void UnitOfMeasurement::setCode(int code)
{
this->code=code;
}
int UnitOfMeasurement::getCode()const
{
return this->code;
}
void UnitOfMeasurement::setTitle(string title)
{
this->title=title;
}
string UnitOfMeasurement::getTitle()const
{
return this->title;
}
abc::IUnitOfMeasurement &UnitOfMeasurement::operator=(const abc::IUnitOfMeasurement &other)
{
this->code=other.getCode();
this->title=other.getTitle();
return *this;
}
int UnitOfMeasurement::operator==(const abc::IUnitOfMeasurement &other)
{
return (this->code==other.getCode());
}
int UnitOfMeasurement::operator!=(const abc::IUnitOfMeasurement &other)
{
return (this->code!=other.getCode());
}
int UnitOfMeasurement::operator<(const abc::IUnitOfMeasurement &other)
{
return (this->code<other.getCode());
}
int UnitOfMeasurement::operator>(const abc::IUnitOfMeasurement &other)
{
return (this->code>other.getCode());
}
int UnitOfMeasurement::operator<=(const abc::IUnitOfMeasurement &other)
{
return (this->code<=other.getCode());
}
int UnitOfMeasurement::operator>=(const abc::IUnitOfMeasurement &other)
{
return (this->code>=other.getCode());
}