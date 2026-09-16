#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Info
{
    int pos, speed;

    bool operator<(const Info& other) const
    {
        return pos < other.pos;
    }
};

class Solution 
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        vector<Info> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = { position[i], speed[i] };
        }

        sort(v.begin(), v.end());

        vector<double> s;

        for (int i = n - 1; i >= 0; i--)
        {
            double time = (double)(target - v[i].pos) / v[i].speed;

            if (s.empty() || time > s.back())
            {
                s.push_back(time);
            }
        }

        return s.size();
    }
};

int main()
{

	return 0;
}