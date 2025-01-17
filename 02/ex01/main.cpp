#include <iostream>
#include "Fixed.hpp"


/*void putfloat_as_bits(float value)
{
    union U{float f; char str[4];} u;
    char bit;
    std::string res;

    u.f = value;
    std::cout << u.f << ":\t";
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            bit = (u.str[i] >> j) & 1;
            res = (char) (bit + '0') + res;
            if(i * 8 + j == 30 || i * 8 + j == 22)
                res = " " + res;
        }
    }
    std::cout << res << std::endl;
}
*/

int main( void ) {

Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}