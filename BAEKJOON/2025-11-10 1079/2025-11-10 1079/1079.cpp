#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, e_idx, ret;
vector<int> nums;
vector<bool> alive;
vector<vector<int>> board;

void go(int night, int left)
{
	if (!alive[e_idx])
	{
		ret = max(ret, night);
		return;
	}

	if (left == 1)
	{
		ret = max(ret, night);
		return;
	}

	if (left % 2 == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (!alive[i] || i == e_idx) continue;

			alive[i] = false;

			for (int j = 0; j < n; j++)
			{
				nums[j] += board[i][j];
			}

			go(night + 1, left - 1);

			for (int j = 0; j < n; j++)
			{
				nums[j] -= board[i][j];
			}

			alive[i] = true;
		}
	}
	else
	{
		int max_num = -1e9, target = -1;
		for (int i = 0; i < n; i++)
		{
			if (!alive[i]) continue;
			if (target == -1 || max_num < nums[i])
			{
				max_num = nums[i];
				target = i;
			}
		}

		alive[target] = false;
		go(night, left - 1);
		alive[target] = true;
	}

}

int main()
{
	cin >> n;
	nums = vector<int>(n);
	alive = vector<bool>(n, true);
	board = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	cin >> e_idx;

	go(0, n);

	cout << ret << "\n";

	return 0;
}