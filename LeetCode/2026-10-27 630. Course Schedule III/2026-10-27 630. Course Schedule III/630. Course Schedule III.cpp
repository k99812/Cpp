#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(), courses.end(),
            [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        });

        priority_queue<int> pq;
        int time = 0;

        for (const vector<int>& course : courses)
        {
            int duration = course[0], lastday = course[1];

            time += duration;
            pq.push(duration);

            if (time > lastday)
            {
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};

int main()
{

    return 0;
}