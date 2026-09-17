#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
    unordered_map<int, int> parent;
    int component;

    int getRoot(int num)
    {
        if (parent.find(num) == parent.end())
        {
            parent[num] = num;
            component++;
        }

        if (parent[num] == num) return num;
        return parent[num] = getRoot(parent[num]);
    }

    void unionParent(int x, int y)
    {
        int root_x = getRoot(x), root_y = getRoot(y);

        if (root_x != root_y)
        {
            parent[root_x] = root_y;
            component--;
        }
    }

public:
    Solution() : component(0) 
    {

    }

    int removeStones(vector<vector<int>>& stones) 
    {
        for (const vector<int>& stone : stones)
        {
            unionParent(stone[0], ~stone[1]);
        }

        return stones.size() - component;
    }
};

int main()
{

	return 0;
}