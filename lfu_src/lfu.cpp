#include <iostream>
#include <cassert>
#include "lfu.hpp"

int main()
{
    int cache_size = 0, requests = 0;
    std::cin >> cache_size >> requests;
    assert(std::cin.good() && "Input error");

    while (cache_size < 0 || requests < 0)
    {
        std::cerr << "Negative cache size or number of request. Enter valid data:\n";
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
            cache.print();
        #endif
    }

    std::cout << hits << "\n";
}