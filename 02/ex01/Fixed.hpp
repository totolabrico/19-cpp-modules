#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <cmath>

class Fixed{

private:
    int _value;
    static int const dec;
public:
    Fixed();
    Fixed (Fixed const &src);
    Fixed (int const value);
    Fixed (float const value);
    ~Fixed();

    Fixed &operator=(Fixed const & rhs);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

};

std::ostream &operator<<(std::ostream &stream, Fixed const &fix);

#endif