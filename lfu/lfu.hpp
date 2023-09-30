#pragma once

#include <unordered_map>
#include <iterator>
#include <map>

template <typename T> class cache_t
{
private:
    size_t size_;
    using FreqIt = typename std::multimap<size_t, T>::iterator;
    std::unordered_map<T, FreqIt> hash_; // hash table of nodes and it's list iterators
    std::multimap<size_t, T> freq_; // contains frequencies and nodes that have the same frequency
public:
    cache_t(size_t size) : size_(size) {}

    bool full() const
    {
        return (hash_.size() == size_);
    }

    bool update(const T& page)
    {
        auto node = hash_.find(page);

        if (node == hash_.end())
        {
            if (full())
            {
                T delete_node = freq_.begin()->second;
                hash_.erase(delete_node);
                freq_.erase(freq_.begin());
            }

            hash_[page] = freq_.emplace(1, page);
            return false;
        }

        size_t cur_node_freq = node->second->first;
        freq_.erase(node->second);
        hash_[page] = freq_.emplace(cur_node_freq + 1, page);
        return true;
    }
  
    void print_cache() const
    {
        for (const auto& [node, it] : hash_)
        {   
            std::cout << node << '(' << it->first << ')' << ' ';
        }
        std::cout << "\n";
    }
};
