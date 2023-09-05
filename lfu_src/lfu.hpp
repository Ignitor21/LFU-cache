#pragma once

#include <list>
#include <unordered_map>
#include <iterator>

template <typename T> class cache_t
{
private:
    size_t size = 0;
    std::list<T> cache_;
    using ListIt = typename std::list<T>::iterator;
    std::unordered_map<T, std::pair<int, ListIt>> hash; // pairs of frequency and iterator to list node
public:
    cache_t(size_t size_)
    {
        size = size_;
    }

    bool full() const
    {
        return (cache_.size() == size);
    }

    int update(T& page)
    {
        if(hash.contains(page))
        {
            ++hash[page].first;
            return 1;
        }

        if (full())
        {
            auto min_freq_node = cache_.begin();
            for (auto node = cache_.begin(); node != cache_.end(); ++node)
            {
                if (hash[*node].first < hash[*min_freq_node].first)
                    min_freq_node = node;
            }

            cache_.erase(min_freq_node);
            cache_.push_back(page);
            hash[page].first = 1;
            auto it = cache_.end();
            hash[page].second = --it;
            return 0;
        }

        
        cache_.push_back(page);
        hash[page].first = 1;
        auto it = cache_.end();
        hash[page].second = --it;
        return 0;
    }

    void print() const
    {
        for (const auto node : cache_)
        {   
            std::cout << node << '(' << hash.at(node).first << ')' << ' ';
        }
        std::cout << "\n";
    }

};

