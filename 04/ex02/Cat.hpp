#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;
protected:
    std::string _type;
public:
    Cat();
    Cat(Animal const &src);
    virtual ~Cat();

    Cat &operator=(Cat const & rhs);
    void setType();
    virtual void makeSound()const;
    Brain *getBrain()const;
};

#endif