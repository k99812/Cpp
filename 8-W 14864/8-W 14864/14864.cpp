#include<iostream>
#include<algorithm>

using namespace std;

int n, m, x, y, visited[100004], a[100004], flag;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		a[x]++, a[y]--;
	}

	for (int i = 1; i <= n; i++)
	{
		a[i] += i;
		visited[a[i]]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] >= 2)
		{
			flag = 1;
			break;
		}
	}

	if (flag)
	{
		cout << -1 << "\n";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}