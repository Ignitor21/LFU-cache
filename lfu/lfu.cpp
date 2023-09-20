#include <iostream>
#include <cassert>
#include <limits>
#include "lfu.hpp"


int main()
{
    int cache_size = 0, requests = 0;
    std::cin >> cache_size >> requests;

    while (!std::cin.good() || cache_size <= 0 || requests <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cerr << "Incorrect input. Enter valid cache size and number of requests:\n";
        std::cin >> cache_size >> requests;   
    }

    cache_t<int> cache(cache_size);
    int hits = 0;

    for (int i = 0; i < requests; ++i)
    {
        int page = 0;
        std::cin >> page;
        hits += cache.update(page);
        #ifdef DEBUG
            std::cout << "Current page: " << page << ' ';
            cache.print_cache();
        #endif
    }

    std::cout << hits << "\n";
    return 0;
}