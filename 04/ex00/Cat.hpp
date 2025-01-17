#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{

protected:
    std::string _type;
public:
    Cat();
    Cat(Animal const &src);
    virtual ~Cat();

    Cat &operator=(Cat const & rhs);
    void setType();
    virtual void makeSound()const;
};

#endif