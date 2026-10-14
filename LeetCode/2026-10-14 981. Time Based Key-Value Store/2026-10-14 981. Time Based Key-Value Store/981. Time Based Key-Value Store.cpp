#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class TimeMap 
{
    unordered_map<string, vector<int>> time_map;
    unordered_map<string, string> value_map;

public:
    TimeMap() 
    {

    }

    void set(string key, string value, int timestamp) 
    {
        time_map[key].push_back(timestamp);
        string temp = key + "#" + to_string(timestamp);
        value_map[temp] = value;
    }

    string get(string key, int timestamp) 
    {
        if (time_map.find(key) == time_map.end()) return "";

        const vector<int>& times = time_map[key];
        auto itr = upper_bound(times.begin(), times.end(), timestamp);

        if (itr == times.begin()) return "";

        itr--;
        int time = *itr;

        string temp = key + to_string(time);
        return value_map[temp];
    }
};

int main()
{

	return 0;
}