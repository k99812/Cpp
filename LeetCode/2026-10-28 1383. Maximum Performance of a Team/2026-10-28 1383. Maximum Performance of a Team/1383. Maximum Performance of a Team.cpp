#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    typedef long long ll;

    struct Info
    {
        int speed, eff;

        bool operator<(const Info& other) const
        {
            return speed > other.speed;
        }
    };

    const int MOD = 1e9 + 7;

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<Info> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = { speed[i], efficiency[i] };
        }

        sort(v.begin(), v.end(), 
            [](const Info& a, const Info& b)
        {
            return a.eff > b.eff;
        });

        priority_queue<Info> pq;
        ll total_speed = 0, ret = 0;

        for (int i = 0; i < n; i++)
        {
            pq.push({ v[i] });
            total_speed += v[i].speed;

            if (k < pq.size())
            {
                int min_speed = pq.top().speed;
                pq.pop();

                total_speed -= min_speed;
            }

            ret = max(ret, total_speed * v[i].eff);
        }

        return ret % MOD;
    }
};

int main()
{

	return 0;
}