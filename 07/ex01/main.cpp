#include "iter.hpp"

void print_float(float *addr)
{
    if(addr)
        std::cout << *addr << std::endl;
}

int main()
{
    int d[2];

    d[0] = 19;
    d[1] = 42;
    iter<int>(d, 2, print<int>);
    iter<int>(d, 2, add<int>);
    iter<int>(d, 2, print<int>);

    float f[2];

    f[0] = 19.19;
    f[1] = 42.42;
    iter<float>(f, 2, print<float>);
    iter<float>(f, 2, add<float>);
    iter<float>(f, 2, print_float);
    return(0);
}