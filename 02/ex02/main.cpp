#include <iostream>
#include "Fixed.hpp"

int main( void ) {

 
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
a = Fixed(0.25f);
Fixed c(115);
std::cout << c - a << std::endl;

return 0;
}