#include <iostream>
#include <cassert>
#include <vector>
#include "perfect.hpp"

int main()
{
    int cache_size = 0, request_number = 0;
    std::cin >> cache_size >> request_number;
    
    while (cache_size < 0 || request_number < 0)
    {
        std::cerr << "Negative cache size or number of request. Enter valid data:\n";
        std::cin >> cache_size >> request_number;   
    }

    Perfect_cache<int> cache(cache_size);
    cache.get_requests(request_number);
    int hits = 0;

    for (int i = 0; i < request_number; ++i)
    {
        hits += cache.update(i);
        #ifdef DEBUG
            cache.print();
        #endif
    }

    std::cout << hits << "\n";
}