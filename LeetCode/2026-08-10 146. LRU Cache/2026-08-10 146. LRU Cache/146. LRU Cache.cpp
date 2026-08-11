#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;

struct Node
{
    int key, val, freq;
    list<int>::iterator itr;
};

class LRUCache 
{
    int capacity, min_freq;
    unordered_map<int, Node> key_map;
    unordered_map<int, list<int>> freq_map;

    void update_frequency(int key)
    {
        int freq = key_map[key].freq;
        list<int>::iterator itr = key_map[key].itr;
        freq_map[freq].erase(itr);

        freq_map[freq].push_front(key);
        key_map[key].itr = freq_map[freq].begin();
    }

public:
    LRUCache(int capacity) : capacity(capacity), min_freq(0)
    {

    }

    int get(int key)
    {
        if (key_map.find(key) == key_map.end()) return -1;

        update_frequency(key);
        return key_map[key].val;
    }

    void put(int key, int value) 
    {
        if (capacity == 0) return;

        if (key_map.find(key) != key_map.end())
        {
            update_frequency(key);
            key_map[key].val = value;
            return;
        }

        if (key_map.size() == capacity)
        {
            int erase_key = freq_map[min_freq].back();
            freq_map[min_freq].pop_back();
            key_map.erase(erase_key);
        }

        min_freq = 1;
        freq_map[1].push_front(key);
        key_map[key] = { key, value, 1, freq_map[1].begin() };
    }
};

int main()
{

    return 0;
}