#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
	int n;

public:
	int totalNQueens(int num) 
	{
		n = num;
		
		return 0;
	}
};

int main()
{
	int n;
	cin >> n;

	Solution sol = Solution();

	int ret = sol.totalNQueens(n);

	cout << ret << "\n";

	return 0;
}