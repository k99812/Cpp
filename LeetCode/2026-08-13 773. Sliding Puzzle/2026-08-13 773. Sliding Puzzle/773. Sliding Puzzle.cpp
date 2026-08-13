#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>

using namespace std;

class Solution 
{
    int n, m;
    vector<vector<int>> board;

    int bfs()
    {
        vector<vector<int>> dir = 
        {
            { 1, 3 },       
            { 0, 2, 4 },    
            { 1, 5 },       
            { 0, 4 },      
            { 1, 3, 5 },    
            { 2, 4 }        
        };

        unordered_map<string, int> visited;
        queue<string> q;

        string start = "", end = "123450";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                start += board[i][j] + '0';
            }
        }

        q.push(start);
        visited[start] = 0;

        while (q.size())
        {
            string now = q.front();
            q.pop();

            if (now == end) return visited[now];

            int idx = now.find('0');
            for (int d : dir[idx])
            {
                string next = now;
                swap(next[idx], next[d]);

                if (visited.find(next) != visited.end()) continue;

                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }

        return -1;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int slidingPuzzle(vector<vector<int>>& inBoard) 
    {
        board = move(inBoard);
        n = board.size(), m = board[0].size();

        return bfs();
    }
};

int main()
{

	return 0;
}