#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int k, n, f;
vector<vector<int>> graph;
vector<int> selected;
vector<int> friend_cnt;

void go(int idx)
{
	if (selected.size() == k)
	{
		for (const int& i : selected)
		{
			cout << i << "\n";
		}
		exit(0);
	}

	for (int i = idx + 1; i <= n; i++)
	{
		if (friend_cnt[i] < k - 1) continue;

		bool flag = true;
		for (const int& member : selected)
		{
			if (!graph[i][member])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			selected.push_back(i);
			go(i);
			selected.pop_back();
		}
	}
}

int main()
{
	cin >> k >> n >> f;

	graph = vector<vector<int>>(n + 1, vector<int>(n + 1));
	friend_cnt = vector<int>(n + 1);

	for (int i = 0; i < f; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;

		friend_cnt[a]++;
		friend_cnt[b]++;
	}

	go(0);

	cout << -1 << "\n";

	return 0;
}