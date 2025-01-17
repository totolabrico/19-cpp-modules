#include "Base.hpp"

int main()
{
    Base *b;
    b = generate();
    if(!b)
        return(1);
    identify(b);
    Base &bb = *b;
    identify(bb);
    delete b;
    return(0);
}