#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class AllOne 
{
    struct Bucket
    {
        int cnt;
        unordered_set<string> keys;
    };

    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> m_map;

public:
    AllOne() 
    {

    }

    void inc(string key) 
    {
        if (m_map.find(key) == m_map.end())
        {
            if (buckets.empty() || buckets.front().cnt != 1)
            {
                buckets.push_front({ 1, {} });
            }

            buckets.front().keys.insert(key);
            m_map[key] = buckets.begin();
            return;
        }

        auto now_itr = m_map[key];
        auto next_itr = next(now_itr);
        int now_cnt = now_itr->cnt;
        
        if (next_itr == buckets.end() || next_itr->cnt != now_cnt + 1)
        {
            next_itr = buckets.insert(next_itr, { now_cnt + 1, {} });
        }

        next_itr->keys.insert(key);
        m_map[key] = next_itr;

        now_itr->keys.erase(key);
        if (now_itr->keys.empty())
        {
            buckets.erase(now_itr);
        }
    }

    void dec(string key) 
    {
        auto now_itr = m_map[key];
        int now_count = now_itr->cnt;

        if (now_count == 1)
        {
            m_map.erase(key);
        }
        else
        {
            auto prev_itr = buckets.end();

            if (now_itr == buckets.begin() || prev(now_itr)->cnt != now_count - 1)
            {
                prev_itr = buckets.insert(now_itr, { now_count - 1, {} });
            }
            else
            {
                prev_itr = prev(now_itr);
            }

            prev_itr->keys.insert(key);
            m_map[key] = prev_itr;
        }

        now_itr->keys.erase(key);
        if (now_itr->keys.empty())
        {
            buckets.erase(now_itr);
        }
    }

    string getMaxKey() 
    {
        if (buckets.empty()) return "";
        return *(buckets.back().keys.begin());
    }

    string getMinKey() 
    {
        if (buckets.empty()) return "";
        return *(buckets.front().keys.begin());
    }
};

int main()
{

	return 0;
}