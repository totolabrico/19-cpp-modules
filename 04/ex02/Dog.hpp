#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;
protected:
    std::string _type;
public:
    Dog();
    Dog(Animal const &src);
    virtual ~Dog();

    Dog &operator=(Dog const & rhs);
    void setType();
    virtual void makeSound()const;
    Brain *getBrain()const;
};

#endif