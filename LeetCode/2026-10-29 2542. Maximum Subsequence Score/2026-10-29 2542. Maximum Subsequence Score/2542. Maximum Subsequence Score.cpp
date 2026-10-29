#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    typedef long long ll;

    struct Node
    {
        int num1, num2;

        bool operator<(const Node& other) const
        {
            return num1 > other.num1;
        }
    };

public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        vector<Node> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = { nums1[i], nums2[i] };
        }

        sort(v.begin(), v.end(), [](const Node& a, const Node& b)
        {
            return a.num2 > b.num2;
        });

        priority_queue<Node> pq;
        ll sum = 0, ret = 0;

        for (int i = 0; i < n; i++)
        {
            pq.push(v[i]);
            sum += v[i].num1;

            if (pq.size() > k)
            {
                sum -= pq.top().num1;
                pq.pop();
            }

            if (pq.size() == k)
            {
                ret = max(ret, sum * v[i].num2);
            }
        }

        return ret;
    }
};

int main()
{

    return 0;
}