#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 500000;
int n, k, visited[2][MAX + 4], cnt = 1;
bool ok = false;
queue<int> q;

int main() 
{
	cin >> n >> k;

	if (n == k)
	{
		cout << "0\n";
		return 0;
	}

	q.push(n);
	visited[0][n] = 1;

	while (q.size())
	{
		k += cnt;
		if (k > MAX) break;
		if (visited[cnt % 2][k])
		{
			ok = true;
			break;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int x = q.front(); q.pop();
			
			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx > MAX) continue;
				if (visited[cnt % 2][nx]) continue;
				visited[cnt % 2][nx] = visited[(cnt + 1) % 2][x] + 1;
				if (nx == k)
				{
					ok = true;
					break;
				}
				q.push(nx);
			}
			if (ok) break;
		}
		if (ok) break;
		cnt++;
	}
	
	ok ? cout << cnt << "\n" : cout << -1 << "\n";
	return 0;
}