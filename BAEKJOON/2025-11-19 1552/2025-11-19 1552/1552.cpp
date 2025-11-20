#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int INF = 2e9;

int n, max_num = -INF, min_num = INF;
vector<vector<int>> board;
vector<bool> col;
vector<int> selection;

int find_cycle()
{
	int cycle = 0;
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;

		cycle++;
		int cur = i;
		while (!visited[cur])
		{
			visited[cur] = true;
			cur = selection[cur];
		}
	}

	return cycle;
}

void dfs(int r)
{
	if (r == n)
	{
		int point = 1;
		for (int i = 0; i < n; i++) point *= board[i][selection[i]];

		int cycle = find_cycle();
		if (cycle % 2 == 0) point *= -1;

		max_num = max(max_num, point);
		min_num = min(min_num, point);
		return;
	}

	for (int c = 0; c < n; c++)
	{
		if (col[c]) continue;
		
		col[c] = true;
		selection[r] = c;

		dfs(r + 1);

		col[c] = false;
	}
}

int main()
{
	cin >> n;

	board = vector<vector<int>>(n, vector<int>(n));
	selection = vector<int>(n);
	col = vector<bool>(n);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			if(isdigit(s[j]))
			{
				board[i][j] = s[j] - '0';
			}
			else
			{
				board[i][j] = -(s[j] - 'A' + 1);
			}
		}
	}

	dfs(0);

	cout << min_num << "\n" << max_num << "\n";

	return 0;
}