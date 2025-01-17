#include <iostream>
#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>


int main()
{
    std::list<int> lst;

    lst.push_back(19);
    lst.push_back(42);
    lst.push_back(100);
    easyfind(lst, 19);
    easyfind(lst, 43);

    std::vector<int> vec;
    vec.push_back(19);
    vec.push_back(42);
    vec.push_back(100);
    easyfind(vec, 100);
    easyfind(vec, 43);

    std::deque<int> deq;
    deq.push_back(19);
    deq.push_back(42);
    deq.push_back(100);
    easyfind(deq, 42);
    easyfind(deq, 43);

    return(0);
}