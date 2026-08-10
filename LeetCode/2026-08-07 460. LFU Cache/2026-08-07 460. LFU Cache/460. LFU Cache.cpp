#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

struct Node
{
    int key, val, freq;
    list<int>::iterator itr;
};

class LFUCache 
{
    int capacity, min_freq;
    unordered_map<int, Node> key_map;
    unordered_map<int, list<int>> freq_map;

    void updateFrequency(int key)
    {
        int f = key_map[key].freq;
        list<int>::iterator itr = key_map[key].itr;

        freq_map[f].erase(itr);
        if (freq_map[f].empty() && f == min_freq)
        {
            min_freq++;
        }

        int new_f = ++key_map[key].freq;
        freq_map[new_f].push_front(key);
        key_map[key].itr = freq_map[new_f].begin();
    }

public:
    LFUCache(int capacity) : capacity(capacity), min_freq(0)
    {

    }

    int get(int key) 
    {
        if (key_map.find(key) == key_map.end()) return -1;

        updateFrequency(key);
        return key_map[key].val;
    }

    void put(int key, int value) 
    {
        if (capacity == 0) return;

        if (key_map.find(key) != key_map.end())
        {
            key_map[key].val = value;
            updateFrequency(key);
            return;
        }

        if (key_map.size() == capacity)
        {
            int delete_key = freq_map[min_freq].back();
            freq_map[min_freq].pop_back();
            key_map.erase(delete_key);
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