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
        assert(std::cin.good() && "Input error");
        hits += cache.update(page);
        cache.print();
    }

    std::cout << "LFU cache hits: " << hits << "\n";
}