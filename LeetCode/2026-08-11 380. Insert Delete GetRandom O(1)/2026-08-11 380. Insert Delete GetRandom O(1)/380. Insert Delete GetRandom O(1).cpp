#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<random>

using namespace std;

class RandomizedSet 
{
    unordered_map<int, int> val_map;
    vector<int> val_arr;

public:
    RandomizedSet()
    {

    }

    bool insert(int val) 
    {
        if (val_map.find(val) != val_map.end()) return false;

        val_map[val] = val_arr.size();
        val_arr.push_back(val);

        return true;
    }

    bool remove(int val) 
    {
        if (val_map.find(val) == val_map.end()) return false;

        int idx = val_map[val], last_val = val_arr.back();

        val_arr[idx] = last_val;
        val_map[last_val] = idx;

        val_map.erase(val);
        val_arr.pop_back();

        return true;
    }

    int getRandom() 
    {
        return val_arr[rand() % val_arr.size()];
    }
};

int main()
{

	return 0;
}