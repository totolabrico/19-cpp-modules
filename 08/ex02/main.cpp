#include <iostream>
#include "MutantStack.hpp"
#include <list>


template <typename T>
static void print_mutantstack(MutantStack <T>&mstack)
{
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while(it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
}

int main()
{
    {
        std::cout << "std::list" << std::endl;
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(10);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "content :" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    {
        MutantStack<int>::iterator it;
        MutantStack<int>::iterator ite;

        std::cout << "MutantStack" << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(10);

        it = mstack.begin();
        ite = mstack.end();
        ++it;
        --it;

        std::cout << "content :" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::cout << std::endl << "Copy tests" << std::endl;
        
        MutantStack<int, std::deque<int> > cpy(mstack);
        MutantStack<int, std::deque<int> > cpy2 = mstack;

        
        std::cout << "MutantStack: ";
        print_mutantstack<int>(mstack);
        std::cout << std::endl;
        std::cout << "Copy (): ";
        print_mutantstack<int>(cpy);
        std::cout << std::endl;
        std::cout << "Copy =: ";
        print_mutantstack<int>(cpy2);
        std::cout << std::endl;

        cpy.push(1000);
        cpy2.pop();
        std::cout << "Copied stacks are edited" << std::endl;

        std::cout << "MutantStack: ";
        print_mutantstack<int>(mstack);
        std::cout << std::endl;
        std::cout << "Copy (): ";
        print_mutantstack<int>(cpy);
        std::cout << std::endl;
        std::cout << "Copy =: ";
        print_mutantstack<int>(cpy2);
        std::cout << std::endl;
    }

    return(0);
}