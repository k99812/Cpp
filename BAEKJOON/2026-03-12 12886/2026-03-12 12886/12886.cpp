#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int SIZE = 1504;

int A, B, C, total;
vector<vector<int>> visited;

void bfs()
{
	if (total % 3 != 0)
	{
		cout << 0 << "\n";
		return;
	}

	visited.assign(SIZE, vector<int>(SIZE, 0));
	vector<int> arr = { A, B, C };
	sort(arr.begin(), arr.end());

	queue<pair<int, int>> q;
	q.push({ arr[0], arr[1] });
	visited[arr[0]][arr[1]] = true;

	while (q.size())
	{
		int a = q.front().first, b = q.front().second;
		int c = total - a - b;
		q.pop();

		if (a == b && b == c)
		{
			cout << 1 << "\n";
			return;
		}

		vector<int> now = { a, b, c };

		for (int i = 0; i < 2; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				if (now[i] < now[j])
				{
					int na = now[i] + now[i], nb = now[j] - now[i];
					int nc = total - na - nb;

					vector<int> next = { na, nb, nc };
					sort(next.begin(), next.end());

					if (visited[next[0]][next[1]]) continue;

					visited[next[0]][next[1]] = true;
					q.push({ next[0], next[1] });
				}
			}
		}
	}

	cout << 0 << "\n";
}

int main()
{
	cin >> A >> B >> C;
	total = A + B + C;

	bfs();

	return 0;
}