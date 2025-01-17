#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{

protected:
    std::string _type;
public:
    Dog();
    Dog(Animal const &src);
    virtual ~Dog();

    Dog &operator=(Dog const & rhs);
    void setType();
    virtual void makeSound()const;
};

#endif