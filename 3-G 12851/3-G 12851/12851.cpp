#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 100000;
int n, k, visited[MAX + 4];
long long cnt[MAX + 4];
queue<int> q;

int main() {

	cin >> n >> k;

	q.push(n);
	visited[n] = 1;
	cnt[n] = 1;

	if (n == k) {
		cout << "0\n" << "1\n";
		return 0;
	}

	while (q.size()) 
	{
		int x = q.front(); q.pop();

		for (int next : {x - 1, x + 1, x * 2})
		{
			if (0 <= next && next <= 100000)
			{
				if (!visited[next]) 
				{
					q.push(next); visited[next] = visited[x] + 1;
					cnt[next] += cnt[x];
				}
				else if(visited[next] == visited[x] + 1)
				{
					cnt[next] += cnt[x];
				}

			}
		}
	}

	cout << visited[k] - 1 << '\n';
	cout << cnt[k] << '\n';
	return 0;
}