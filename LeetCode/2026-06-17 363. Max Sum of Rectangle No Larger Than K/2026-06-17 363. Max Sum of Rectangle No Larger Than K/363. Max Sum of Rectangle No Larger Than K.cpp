#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n, m, k;
    vector<vector<int>> board;

public:
    Solution() : n(0), m(0), k(0)
    {

    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) 
    {
        board = move(matrix);
        n = board.size();
        m = board[0].size();
        k = K;

        int ret = -INF;
        
        for (int left = 0; left < m; left++)
        {
            vector<int> row_sum(n, 0);
            
            for (int right = left; right < m; right++)
            {
                for (int i = 0; i < n; i++)
                {
                    row_sum[i] += board[i][right];
                }

                set<int> prefix;

                prefix.insert(0);
                
                int now = 0;

                for (int sum : row_sum)
                {
                    now += sum;

                    set<int>::iterator itr = prefix.lower_bound(now - k);

                    if (itr != prefix.end())
                    {
                        ret = max(ret, now - *itr);
                    }

                    prefix.insert(now);
                }
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}