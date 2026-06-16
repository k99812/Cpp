#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    bool canMeasureWater(int x, int y, int target) 
    {
        if (target > x + y) return false;
        if (target == x || target == y || target == x + y) return true;

        const int dir[4] = { +x, -x, +y, -y };

        queue<int> q;
        vector<bool> visited(x + y + 1, false);

        q.push(0);
        visited[0] = true;

        while (q.size())
        {
            int now = q.front();
            q.pop();

            if (now == target) return true;
            
            for (int i = 0; i < 4; i++)
            {
                int next = now + dir[i];

                if (next < 0 || next > x + y || visited[next]) continue;

                visited[next] = true;
                q.push(next);
            }
        }

        return false;
    }
};

int main()
{

	return 0;
}