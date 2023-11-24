#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 200000;
int n, k, visited[MAX + 4], prev_r[MAX + 4], ret;
vector<int> v;
queue<int> q;

int main()
{
	cin >> n >> k;

	q.push(n);
	visited[n] = 1;

	while (q.size())
	{
		int x = q.front(); q.pop();

		if (x == k)
		{
			ret = visited[x];
		}

		for (int next : {x - 1, x + 1, x * 2})
		{
			if (next < 0 || next >= MAX) continue;
			if (visited[next]) continue;
			q.push(next); visited[next] = visited[x] + 1;
			prev_r[next] = x;
		}
	}
	for (int i = k; i != n; i = prev_r[i])
	{
		v.push_back(i);
	}

	v.push_back(n);

	reverse(v.begin(), v.end());
	cout << ret - 1 << "\n";
	for (int i : v) cout << i << " ";
	return 0;
}