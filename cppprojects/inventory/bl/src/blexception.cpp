#include<bl/blexception>
#include<iostream>
#include<map>
using namespace std;
using namespace inventory;
using namespace business_layer;
BLException::BLException()
{
this->genericMessage="";
}
BLException::BLException(string genericMessage)
{
this->genericMessage=genericMessage;
}
BLException::BLException(const BLException &other)
{
this->genericMessage=other.genericMessage;
this->exceptions=other.exceptions;
}
BLException &BLException::operator=(const BLException &other)
{
this->genericMessage=other.genericMessage;
this->exceptions=other.exceptions;
}
BLException::~BLException()throw()
{
//nothing
}
const char *BLException::what()const throw()
{
return this->genericMessage.c_str();
}
int BLException::hasGenericException()
{
return this->genericMessage.length()>0;
}
string BLException::getGenericException()
{
return this->genericMessage.c_str();
}
void BLException::setGenericException(string genericMessage)
{
this->genericMessage=genericMessage;
}
int BLException::hasPropertyException(string property)
{
return this->getPropertyExceptionsCount()>0;
}
string BLException::getPropertyException(string property)
{
map<string,string>::iterator i=this->exceptions.find(property);
if(i==this->exceptions.end())
{
return string("");
}
return i->second;
}
void BLException::addPropertyException(string property,string exceptions)
{
this->exceptions.insert(pair<string,string>(property,exceptions));
}
int BLException::hasExceptions()
{
int exceptionCount=0;
if(this->genericMessage.length()>0)exceptionCount++;
if(this->exceptions.size()>0)exceptionCount++;
return exceptionCount>0;
}
int BLException::getPropertyExceptionsCount()
{
return this->exceptions.size()>0;
}
