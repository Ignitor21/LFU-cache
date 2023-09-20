#pragma once

#include <map>
#include <unordered_map>
#include <iterator>
#include <set>
#include <vector>
#include <cassert>

template <typename T> class Perfect_cache
{
private:
    size_t size_;
    using HashIt = typename std::set<T>::iterator;
    std::vector<T> requests_;
    std::set<T> hash_; 
    std::unordered_multimap<T, size_t> entry_;
    std::map<size_t, HashIt, std::greater<size_t>> index_map_;
public:
    Perfect_cache(size_t size)
    {
        size_ = size;
    }

    bool full() const
    {
        return (hash_.size() == size_);
    }

    void get_requests(int n) // writing pages in the vector of requests
    {
        requests_.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            T tmp;
            std::cin >> tmp;
            requests_.push_back(tmp);
        }
    }

    void hash_entry()
    {
        for (size_t i = requests_.size() - 1; i != 0; --i)
            entry_.emplace(requests_[i], i);
        entry_.emplace(requests_[0], 0);
    }

    bool update(size_t index) // cache updating
    {
        assert(hash_.size() == index_map_.size());
        assert(index <  requests_.size());
        
        T page = requests_[index];
        #ifdef DEBUG
            std::cout << "Cur page: " << page << "\n";
        #endif
        auto hit = hash_.find(page);


        entry_.erase(entry_.find(page));
        auto next_entry_it = entry_.find(page);

        if (hit == hash_.end())
        {
            if (next_entry_it == entry_.end())
            {
                return false;
            }

            if (full())
            {
                auto max_freq_node_it = index_map_.begin();
                hash_.erase((*max_freq_node_it).second);
                index_map_.erase(max_freq_node_it);
            }
            size_t tmp = (*next_entry_it).second;
            index_map_[tmp] = (hash_.emplace(page)).first;
            return false;
        }

        if (next_entry_it == entry_.end())
        {
            hash_.erase(page);
            index_map_.erase(index_map_.find(index));
        }
        else
        {
            index_map_.erase(index);
            index_map_[next_entry_it->second] = hash_.find(page);
        }

        return true;
    }
    
    void print_nodes() const 
    {
        for (const auto& node : hash_)
        {   
            std::cout << node << ' ';
        }
        std::cout << "\n";
    }

    void print_index() const 
    {
        std::cout << "Index list: ";
        for (const auto& [freq, it] : index_map_)
        {   
            std::cout << freq << ' ';
        }
        std::cout << "\n";
    }

};