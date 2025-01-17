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
    int operator<(Fixed const & other) const;
    int operator>(Fixed const & other) const;
    int operator<=(Fixed const & other) const;
    int operator>=(Fixed const & other) const;
    int operator==(Fixed const & other) const;
    int operator!=(Fixed const & other) const;
    float operator+(Fixed const & other);
    float operator-(Fixed const & other);
    float operator*(Fixed const & other);
    float operator/(Fixed const & other);
    float operator++();
    float operator++(int);
    float operator--();
    float operator--(int);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static float min(Fixed &a, Fixed &b);
    static float min(Fixed const &a, Fixed const &b);
    static float max(Fixed &a, Fixed &b);
    static float max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &stream, Fixed const &fix);

#endif