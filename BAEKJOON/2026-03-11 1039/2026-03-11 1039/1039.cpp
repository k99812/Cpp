#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

string n;
int k;
bool visited[1000001][11];

int bfs()
{
	int ret = -1;
	queue<pair<int, string>> q;
	q.push({ 0, n });
	visited[stoi(n)][0] = true;

	while (q.size())
	{
		int idx = q.front().first;
		string num = q.front().second;
		q.pop();

		if (idx == k)
		{
			ret = max(ret, stoi(num));
			continue;
		}

		int len = num.size();
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				string next = num;

				swap(next[i], next[j]);

				if (next[0] == '0' || visited[stoi(next)][idx + 1]) continue;

				visited[stoi(next)][idx + 1] = true;
				q.push({ idx + 1, next });
			}
		}
	}

	return ret;
}

int main()
{
	cin >> n >> k;

	cout << bfs() << "\n";

	return 0;
}