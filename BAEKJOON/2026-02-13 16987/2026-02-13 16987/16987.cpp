#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, ret = -1;
vector<pair<int, int>> arr;

void go(int now)
{
	if (now == n)
	{
		int cnt = 0;
		for (const pair<int, int>& p : arr)
		{
			if (p.first <= 0) cnt++;
		}

		ret = max(ret, cnt);

		return;
	}

	if (arr[now].first <= 0)
	{
		go(now + 1);
		return;
	}

	bool flag = false;

	for (int i = 0; i < n; i++)
	{
		if (i == now || arr[i].first <= 0) continue;

		flag = true;

		arr[now].first -= arr[i].second;
		arr[i].first -= arr[now].second;
		go(now + 1);
		arr[now].first += arr[i].second;
		arr[i].first += arr[now].second;
	}

	if (!flag) go(now + 1);
}

int main()
{
	cin >> n;

	arr.assign(n, {});

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	go(0);

	cout << ret << "\n";

	return 0;
}