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

    }

public:
    LRUCache(int capacity) : capacity(capacity), min_freq(0)
    {

    }

    int get(int key)
    {

    }

    void put(int key, int value) 
    {

    }
};

int main()
{

    return 0;
}