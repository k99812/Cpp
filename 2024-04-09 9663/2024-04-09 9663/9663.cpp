#include<iostream>
#include<algorithm>

using namespace std;

int n, col[18], ret;

bool check(int num)
{
	for (int i = 0; i < num; i++)
	{
		if (col[i] == col[num] || abs(col[num] - col[i]) == num - i)
		{
			return false;
		}
	}
	return true;
}

void go(int x)
{
	if (x == n)
	{
		ret++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		col[x] = i;
		if (check(x))
		{
			go(x + 1);
		}
	}
}

int main()
{
	cin >> n;

	go(0);

	cout << ret << "\n";

	return 0;
}