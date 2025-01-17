#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{        
    if (argc != 2)
        return(1);
    RPN rpn(argv[1]);
    try
    {
        std::cout << rpn.compute() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}