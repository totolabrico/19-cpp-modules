#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T const & tab, int const & needle)
{
    typedef typename T::const_iterator const_iterator;
    if (std::find<const_iterator, int>(tab.begin(), tab.end(), needle) == tab.end())
    {
        std::cout << "did not find " << needle << " !" << std::endl;
        return(0);
    }
    std::cout << "found " << needle << " !" << std::endl;
    return(1);
}

#endif