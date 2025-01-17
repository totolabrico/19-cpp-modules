#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed{

private:
    int _value;
    static int const dec = 8;
public:
    Fixed();
    Fixed (Fixed const &src);
    ~Fixed();

    Fixed &operator=(Fixed const & rhs);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif