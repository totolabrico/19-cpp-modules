#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <list>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

unsigned int Jacobsthal(unsigned int aim);

template <typename C, typename P>
class PmergeMe
{
    public:
        PmergeMe <C, P> (){}

        PmergeMe <C, P> (PmergeMe <C, P> const & src)
        {
            *this = src;
        }

        ~PmergeMe <C, P> (){};

        PmergeMe <C, P> &operator=(PmergeMe <C, P> const & src)
        {
            if(this != &src)
                *this = src;
            return *this;
        }
        
        void printList(C lst)
        {
            typedef typename C::const_iterator const_it;

            const_it it = lst.begin();
            while(it != lst.end())
            {
                std::cout << *it << " ";
                it++;
            }
            std::cout << std::endl;
        }

        C createIndexes(unsigned long size)
        {
            unsigned long i, j, a, jacob;
            C res;
            
            i = a = 0;
            while(res.size() < size)
            {
                jacob = Jacobsthal(i + 1);
                if(jacob > size - a)
                    jacob = size - a;
                j = 0;
                while(j < jacob && res.size() < size)
                {
                    res.push_back(jacob + a - 1 - j);
                    j++;
                }
                a += jacob;
                i++;
            }
            return(res);
        }

        P createPairs(C lst)
        {
            unsigned int a, b;
            typename C::iterator it, ite;
            P pairs;
            
            it = lst.begin();
            ite = lst.end();
            while(it != ite)
            {
                a = *it;
                it++;
                if(it == ite)
                    break;
                b = *it;
                std::pair<unsigned int, unsigned int> p(a, b);
                if(a > b)
                    std::swap(p.first, p.second);
                pairs.push_back(p);
                it++;
            }
            return (pairs);
        }

        P merge(P a, P b)
        {
            P res;

            while(a.size() > 0 && b.size() > 0)
            {
                if (a.front().second < b.front().second)
                {
                    res.push_back(a.front());
                    a.pop_front();
                }
                else
                {
                    res.push_back(b.front());
                    b.pop_front();
                }
            }
            while(a.size() > 0)
            {
                res.push_back(a.front());
                a.pop_front();
            }

            while(b.size() > 0)
            {
                res.push_back(b.front());
                b.pop_front();
            }
            return res;
        }

        P mergeSort(P lst)
        {
            typedef typename P::iterator iterator;

            iterator it;
            iterator ite;
            P a;
            P b;
            unsigned long i, half, size;

            size = lst.size();
            if(size <= 1)
                return(lst);
            it = lst.begin();
            ite = lst.end();
            half = lst.size() / 2;
            i = 0;
            while (lst.size() > 0)
            {
                if (i < half)
                    a.push_back(lst.front());
                else
                    b.push_back(lst.front());
                lst.pop_front();
                i++;
            }
            a = mergeSort(a);
            b = mergeSort(b);
            return merge(a, b);
        }

        void insertion(C & lst, unsigned int value, unsigned int max)
        {
            typename C::iterator it, ite;
            unsigned int min, half, i;

            min = 0;
            half = max / 2;
            it = lst.begin();
            std::advance(it, half);
            i = 0;
            while(*it != value && max - min > 0)
            {
                if(value < *it)
                    max = half;
                else
                    min = half + 1;
                half = (max - min) / 2 + min;
                it = lst.begin();
                std::advance(it, half);
                i++;
            }
            lst.insert(it, value);
        }

        void insertionSort(C & lst, P pairs, unsigned long size)
        {
            C indexes;
            typename C::iterator it, ite;
            typename P::iterator pit, pite;
            unsigned int index, new_index;

            pairs.pop_front();
            pit = pairs.begin();
            pite = pairs.end();
            while(pit != pite)
            {
                lst.push_back(pit->second);
                pit++;
            }
            indexes = createIndexes((size - 2) / 2);
            it  = indexes.begin();
            ite = indexes.end();
            pit = pairs.begin();
            while(it != ite)
            {
                index = *it;
                pit = pairs.begin();
                std::advance(pit, index);
                new_index = std::distance(lst.begin(), std::find(lst.begin(), lst.end(), pit->second));
                insertion(lst, pit->first, new_index);
                it++;
            }
        }

        C mergeInsertionSort(C lst)
        {
            unsigned long size;
            bool odd;
            typename C::iterator it, ite;
            P pairs;
            C res;

            size = lst.size();
            if(size <= 1)
                return (lst);
            odd = static_cast<bool>(size % 2);
            pairs = createPairs(lst);
            pairs = mergeSort(pairs);
            res.push_back(pairs.begin()->first);
            res.push_back(pairs.begin()->second);
            if(size == 2)
                return(res);
            insertionSort(res, pairs, size);
            if(odd)
                insertion(res, lst.back(), size);
            return(res);
        }

        C sort(char *argv)
        {        
            C lst;
            std::string line = argv;
            std::stringstream stream(line);
            std::string v;

            while(getline(stream, v, ' '))
                lst.push_back(atoi(v.c_str()));
            return (mergeInsertionSort(lst));
        }
};

#endif