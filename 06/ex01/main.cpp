#include "Serializer.hpp"

int main()
{
    Data d;
    uintptr_t p;
    Data *ad;

    p = Serializer::serialize(&d);
    std::cout << &d << std::endl;
    std::cout << p << std::endl;

    ad = Serializer::deserialize(p);
    std::cout << ad << std::endl;
    return(0);
}