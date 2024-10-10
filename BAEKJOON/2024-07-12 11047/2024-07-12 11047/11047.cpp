#include<iostream>
#include<algorithm>

using namespace std;

int n, k, coin[14], ret;

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	int mod = k;
	while (true)
	{
		if (mod == 0)
		{
			break;
		}

		for (int i = n; i > 0; i--)
		{
			if (mod % coin[i] < mod)
			{
				ret += mod / coin[i];
				mod %= coin[i];
			}
		}
	}

	cout << ret << "\n";

	return 0;
}