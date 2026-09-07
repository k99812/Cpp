#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class MedianFinder 
{
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

public:
    MedianFinder() 
    {

    }

    void addNum(int num) 
    {
        if (max_pq.size() == min_pq.size()) max_pq.push(num);
        else min_pq.push(num);

        if (min_pq.size() && max_pq.size() && min_pq.top() < max_pq.top())
        {
            int min_num = min_pq.top();
            int max_num = max_pq.top();

            min_pq.pop();
            max_pq.pop();

            min_pq.push(max_num);
            max_pq.push(min_num);
        }
    }

    double findMedian() 
    {
        if (max_pq.size() == min_pq.size())
        {
            return (max_pq.top() + min_pq.top()) / 2.0;
        }

        return max_pq.top();
    }
};


int main()
{

	return 0;
}