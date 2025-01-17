#ifndef WRONGWrongCat_HPP
#define WRONGWrongCat_HPP
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

protected:
    std::string _type;
public:
    WrongCat();
    WrongCat(WrongAnimal const &src);
    virtual ~WrongCat();

    WrongCat &operator=(WrongCat const & rhs);
    void setType();
    void makeSound()const;
};

#endif