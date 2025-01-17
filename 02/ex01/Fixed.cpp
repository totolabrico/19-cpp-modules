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
    this->_value =  (int)(value * (1 << dec) + 1);
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
    return ((float)(this->_value) / (1 << dec));
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

std::ostream &operator<<(std::ostream &stream, Fixed const &fix){
    stream << fix.toFloat();
    return (stream);
}