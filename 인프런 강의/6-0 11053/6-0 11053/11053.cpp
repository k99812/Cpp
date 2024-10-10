#include<iostream>
#include<algorithm>

using namespace std;

int n, a[1004], cnt[1004], ret;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		int value = 0;

		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && value < cnt[j]) value = cnt[j];
		}
		cnt[i] = value + 1;
		ret = max(ret, cnt[i]);
	}

	cout << ret << "\n";

	return 0;
}