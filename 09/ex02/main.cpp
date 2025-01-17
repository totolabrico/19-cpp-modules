#include <iostream>
#include <list>
#include <deque>
#include "PmergeMe.hpp"
#include <sys/time.h>

/* !!!!!!!!!!!!!!!!!!! la liste passé en parametre n'est pas entre guillemets !!!!!!!!!!!!!!!!! */

int main(int argc, char **argv)
{        
    struct timeval tv_start, tv_end;
    long long start, end, dif_list, dif_deque;
    if (argc != 2)
        return(1);

    /* std::list */
    PmergeMe <std::list<unsigned int>, std::list<std::pair<unsigned int, unsigned int> > > ml;
    gettimeofday(&tv_start, NULL);
    std::list<unsigned int> res_list = ml.sort(argv[1]);
    gettimeofday(&tv_end, NULL);
    start = tv_start.tv_sec * 1000000LL + tv_start.tv_usec;
    end = tv_end.tv_sec * 1000000LL + tv_end.tv_usec;
    dif_list = end - start;

    /* std::deque */
    PmergeMe <std::deque<unsigned int>, std::deque<std::pair<unsigned int, unsigned int> > > md;
    gettimeofday(&tv_start, NULL);
    std::deque<unsigned int> res_deque = md.sort(argv[1]);
    gettimeofday(&tv_end, NULL);
    start = tv_start.tv_sec * 1000000LL + tv_start.tv_usec;
    end = tv_end.tv_sec * 1000000LL + tv_end.tv_usec;
    dif_deque = end - start;

    std::cout << "before: " << argv[1] << std::endl;
    std::cout << "after: ";
    ml.printList(res_list);
    //ml.printList(res_deque);
    std::cout << "Time to process a range of " << res_list.size() << " elements with std::list : " << dif_list << " us" << std::endl;
    std::cout << "Time to process a range of " << res_deque.size() << " elements with std::deque : " << dif_deque << " us" << std::endl;

    return (0);
}