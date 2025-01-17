#include "Fixed.hpp"

int const Fixed::dec = 8;

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
};
Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
};

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << dec;
};

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value =  (int)(value * (1 << dec));
};

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat( void ) const
{
    return (((float)(this->_value)) / (1 << dec));
}

int Fixed::toInt( void ) const
{
    return (this->_value >> dec);
}

Fixed &Fixed::operator=(Fixed const & src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &src)
        this->_value = src.getRawBits();
    return *this;
}

int Fixed::operator<(Fixed const & src)const
{
    if(_value < src.getRawBits())
        return(1);
    return(0);
}

int Fixed::operator>(Fixed const & src)const
{
    if(_value > src.getRawBits())
        return(1);
    return(0);
}

int Fixed::operator<=(Fixed const & src)const
{
    if(_value <= src.getRawBits())
        return(1);
    return(0);
}

int Fixed::operator>=(Fixed const & src)const
{
    if(_value >= src.getRawBits())
        return(1);
    return(0);
}

int Fixed::operator==(Fixed const & src)const
{
    if(_value == src.getRawBits())
        return(1);
    return(0);
}

int Fixed::operator!=(Fixed const & src)const
{
    if(_value != src.getRawBits())
        return(1);
    return(0);
}

float Fixed::operator+(Fixed const & src)
{
    Fixed temp;

    temp.setRawBits(getRawBits() + src.getRawBits());
    return(temp.toFloat());
}

float Fixed::operator-(Fixed const & src)
{
    Fixed temp;

    temp.setRawBits(getRawBits() - src.getRawBits());
    return(temp.toFloat());
}

float Fixed::operator*(Fixed const & src)
{
    Fixed temp;

    temp.setRawBits(((getRawBits() + 1) * (src.getRawBits())) >> dec);
    return(temp.toFloat());
}

float Fixed::operator/(Fixed const & src)
{
    return(toFloat() / src.toFloat());
}

float Fixed::operator++()
{
    _value++;
    return(toFloat());
}


float Fixed::operator++(int)
{
    float res = toFloat(); 
    _value++;
    return(res);
}

float Fixed::operator--()
{
    _value--;
    return(toFloat());
}


float Fixed::operator--(int)
{
    float res = toFloat(); 
    _value--;
    return(res);
}

float Fixed::min(Fixed &a, Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return(a.toFloat());
    else
        return(b.toFloat());
}

float Fixed::min(Fixed const &a, Fixed const &b)
{
    if(a.getRawBits() < b.getRawBits())
        return(a.toFloat());
    else
        return(b.toFloat());
}

float Fixed::max(Fixed &a, Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return(a.toFloat());
    else
        return(b.toFloat());
}

float Fixed::max(Fixed const &a, Fixed const &b)
{
    if(a.getRawBits() > b.getRawBits())
        return(a.toFloat());
    else
        return(b.toFloat());
}

std::ostream &operator<<(std::ostream &stream, Fixed const &fix){
    stream << fix.toFloat();
    return (stream);
}