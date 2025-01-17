#ifndef WRONGWrongAnimal_HPP
#define WRONGWrongAnimal_HPP
#include <iostream>

class WrongAnimal{

protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const &src);
    virtual ~WrongAnimal();

    WrongAnimal &operator=(WrongAnimal const & rhs);
    void setType(std::string type);
    std::string const &getType() const;
    void makeSound()const;
};

#endif