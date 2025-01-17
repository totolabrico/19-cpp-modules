#include "Array.hpp"

int main()
{

Array <int> array(10);

try
{
    array[0] = 19;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

Array <int> array2(array);

Array <int> array3;

array3 = array;

try
{
    array2[0] += 1;
    array3[10] -= 1; /* out of range */
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

try
{
    std::cout << array[0] << std::endl;
    std::cout << array2[0] << std::endl;
    std::cout << array3[0] << std::endl;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}

return(0);
}