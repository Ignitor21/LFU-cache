#pragma once

#include <list>
#include <unordered_map>
#include <iterator>

template <typename T> class Perfect_cache
{
private:
    std::list<T> cache_;
    size_t size = 0;
    using ListIt = typename std::list<T>::iterator;
    std::vector<T> requests;
    std::unordered_map<T, std::pair<ListIt, size_t>> hash; //Pair of list iterator to key in list and distance between current page and her next entry
    size_t requests_size = 0;
public:
    Perfect_cache(size_t size_)
    {
        size = size_;
    }

    bool full() const
    {
        return (cache_.size() == size);
    }

    void get_requests(int n) // writing pages in the vector of requests
    {
        requests.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> requests[i];
        }
        requests_size = n;
    }

    int dist(size_t index) const // return distance between requests[index] value and its next entry
    {
        T find_value = requests[index];

        for(size_t i = index + 1; i < requests_size; ++i)
        {
            if (requests[i] == find_value)
                return (i - index);
        }

        return requests_size;
    }

    void decrement_dist() // decrements all distances by 1
    {
        for (auto &[key, value]: hash)
        {
            if (value.second != requests_size)
                --(value.second);
        }   
    }

    int update(int index) // cache updating
    {
        T page = requests[index];
        decrement_dist();

        if (hash.contains(page))
        {
            hash[page].second = dist(index);
            return 1;
        }

        if (full())
        {
            size_t max_dist = 0;
            ListIt delete_node;

            for (const auto &[key, value]: hash)
            {
                if (value.second > max_dist)
                {
                    delete_node = value.first;
                    max_dist = value.second;
                }
            }

            cache_.erase(delete_node);
            hash.erase(*delete_node);
            cache_.push_back(page);
            ListIt end = cache_.end();
            hash[page].first = --end;
            hash[page].second = dist(index);  
            return 0;  
        }

        cache_.push_back(page);
        ListIt end = cache_.end();
        hash[page].first = --end;
        hash[page].second = dist(index);
        return 0;
    }
    
    void print() const //prints out cache with distant to the next entry of every node
    {
        for (const auto node : cache_)
        {   
            std::cout << node << '(' << hash.at(node).second << ')' << ' ';
        }
        std::cout << "\n";
    }
};