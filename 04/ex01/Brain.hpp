#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain{

private:
    std::string _ideas[100];
public:
    Brain();
    Brain(std::string const ideas[100]);
    Brain(Brain const &src);
    ~Brain();

    Brain &operator=(Brain const & rhs);
    std::string getIdea(unsigned int id) const;
};

#endif