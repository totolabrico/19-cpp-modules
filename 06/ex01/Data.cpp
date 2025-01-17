#include "Data.hpp"

Data::Data() : _value(19){};

Data::Data(Data const & src)
{
    if(this != &src)
        _value = src.getValue();
};

Data::~Data(){};

int Data::getValue()const
{
    return _value;
}

Data & Data::operator=(Data const & src)
{
    if(this != &src)
        _value = src.getValue();
    return *this; 
}