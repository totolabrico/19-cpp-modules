#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal{

protected:
    std::string _type;
public:
    Animal();
    Animal(std::string type);
    Animal(Animal const &src);
    virtual ~Animal();

    Animal &operator=(Animal const & rhs);
    void setType(std::string type);
    std::string const &getType() const;
    virtual void makeSound()const;
};

#endif