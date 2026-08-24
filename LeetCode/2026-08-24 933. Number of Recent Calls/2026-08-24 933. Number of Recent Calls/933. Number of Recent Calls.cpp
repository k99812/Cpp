#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class RecentCounter 
{
    const int OFFSET = 3000;

    queue<int> q;

public:
    RecentCounter() 
    {

    }

    int ping(int t) 
    {
        q.push(t);

        while (q.size() && q.front() < t - OFFSET)
        {
            q.pop();
        }

        return q.size();
    }
};

int main()
{

	return 0;
}