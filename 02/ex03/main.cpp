#include <iostream>
#include "Point.hpp"

int main( void ) 
{
    Point const a(0, 0);
    Point const b(0, 1);
    Point const c(1, 0);
    Point const p(0, 0.1);

    std::cout << bsp(a, b, c, p) << std::endl;

    return 0;
}