#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

const int INF = 1e9;
const int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int n, m, k;
vector<string> board;
unordered_map<string, int> un_map;

void dfs(int y, int x, string s)
{
	un_map[s]++;

	if (s.size() == 5) return;

	for (int i = 0; i < 8; i++)
	{
		int ny = (n + y + dy[i]) % n, nx = (m + x + dx[i]) % m;

		dfs(ny, nx, s + board[ny][nx]);
	}
}

int main()
{
	cin >> n >> m >> k;

	board.assign(n, "");

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			string temp = "";
			temp += board[i][j];
			dfs(i, j, temp);
		}
	}

	for (int i = 0; i < k; i++)
	{
		string str;
		cin >> str;
		cout << un_map[str] << "\n";
	}

	return 0;
}