#include "Base.hpp"

Base *generate(void)
{
    int r;

    srand(time(NULL));
    r = rand() % 3;

    if(r == 0)
        return dynamic_cast <Base *> (new A);
    if(r == 1)
        return dynamic_cast <Base *> (new B);
    return dynamic_cast <Base *> (new C);
}

void identify(Base* p)
{
    A *a = dynamic_cast <A *> (p);
    B *b = dynamic_cast <B *> (p);
    C *c = dynamic_cast <C *> (p);

    if(a)
        std::cout << "A" << std::endl;
    else if(b)
        std::cout << "B" << std::endl;
    else if(c)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
 try
 {
    (void)dynamic_cast <A &> (p);
    std::cout << "A" << std::endl;
 }
 catch (std::exception & bc)
 {}
 try
 {
    (void)dynamic_cast <B &> (p);
    std::cout << "B" << std::endl;
 }
 catch (std::exception & bc)
 {} try
 {
    (void)dynamic_cast <C &> (p);
    std::cout << "C" << std::endl;
 }
 catch (std::exception & bc)
 {}

}