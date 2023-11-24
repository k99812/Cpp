#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 104;
int n, l, map[MAX][MAX], bmap[MAX][MAX], ret;

void solve(int val[MAX][MAX])
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		int j;
		for (j = 0; j < n - 1; j++)
		{
			if (val[i][j] == val[i][j + 1]) cnt++;
			else if (val[i][j] + 1 == val[i][j + 1] && cnt >= l) cnt = 1;
			else if (val[i][j] - 1 == val[i][j + 1] && cnt >= 0) cnt = -l + 1;
			else break;
		}
		if (j == n - 1 && cnt >= 0) ret++;
	}
	return;
}

int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			bmap[j][i] = map[i][j];
		}
	}
	solve(map);
	solve(bmap);
	cout << ret << "\n";

	return 0;
}