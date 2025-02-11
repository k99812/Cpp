#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int n = 9;

bool canNum(int y, int x, int num, vector<vector<int>>& graph)
{
	for (int i = 0; i < n; i++)
	{
		if (graph[y][i] == num) return false;

		if (graph[i][x] == num) return false;

		int ny = y / 3 * 3 + i / 3;
		int nx = x / 3 * 3 + i % 3;

		if (graph[ny][nx] == num) return false;
	}

	return true;
}

void go(int idx, vector<vector<int>>& graph, const vector<pair<int, int>> empty)
{
	if (idx == empty.size())
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << graph[i][j];
			}
			cout << "\n";
		}

		exit(0);
	}

	int y = empty[idx].first, x = empty[idx].second;

	for (int i = 1; i <= 9; i++)
	{
		if (canNum(y, x, i, graph))
		{
			graph[y][x] = i;
			go(idx + 1, graph, empty);
			graph[y][x] = 0;
		}
	}

	return;
}

int main()
{
	vector<vector<int>> graph(n);
	for (vector<int>& v : graph) v.resize(n);

	vector<pair<int, int>> empty;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = s[j] - '0';
			if (!graph[i][j]) empty.push_back({ i, j });
		}
	}

	go(0, graph, empty);

	return 0;
}