#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v, visited;

int main()
{
	cin >> n;

	v = visited = vector<int>(n);

	for (int& i : v)
	{
		cin >> i;
	}

	int now = 0, cnt = 0;

	while (cnt < n)
	{
		cout << now + 1 << " ";
		int next = v[now];
		visited[now] = true;
		cnt++;

		if (cnt == n) break;

		int step = 0;
		if (next > 0)
		{
			while (step < next)
			{
				now = (now + 1) % n;
				if (!visited[now]) step++;
			}
		}
		else
		{
			while (step < -next)
			{
				now = (now - 1 + n) % n;
				if (!visited[now]) step++;
			}
		}
	}

	cout << "\n";

	return 0;
}