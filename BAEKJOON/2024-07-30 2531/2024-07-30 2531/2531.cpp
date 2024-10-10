#include<iostream>
#include<algorithm>

#define MAX_NUM 30000

using namespace std;

int n, d, k, c, a[MAX_NUM], ret;

int main()
{
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;

		int visited[3004] = { 0, };

		for (int j = i; j < i + k; j++)
		{
			if (!visited[a[j % n]])
			{
				visited[a[j % n]] = true;
				cnt++;
			}
		}

		if (!visited[c]) cnt++;

		ret = max(cnt, ret);
	}

	cout << ret << "\n";

	return 0;
}