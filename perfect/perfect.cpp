#include <iostream>
#include <cassert>
#include <vector>
#include <limits>
#include "perfect.hpp"

int main()
{
    int cache_size = 0, request_number = 0;
    std::cin >> cache_size >> request_number;
    
    while (!std::cin.good() || cache_size <= 0 || request_number <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cerr << "Incorrect input. Enter valid data:\n";
        std::cin >> cache_size >> request_number;   
    }

    Perfect_cache<int> cache(cache_size);
    cache.get_requests(request_number);
    cache.hash_entry();
    int hits = 0;

    for (int i = 0; i < request_number; ++i)
    {
        hits += cache.update(i);
        #ifdef DEBUG
            cache.print_nodes();
            cache.print_index();
            std::cout << "\n";
        #endif
    }

    std::cout << hits << "\n";
    return 0;
}