#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;

ll a, b;

ll go(ll idx, ll num)
{
	if (num > b)
	{
		return INT64_MAX;
	}

	if (num == b)
	{
		return idx;
	}

	ll ret = INT64_MAX;
	ret = min(go(idx + 1, num * 2), go(idx + 1, (num * 10) + 1));

	return ret;
}

ll bfs(ll idx)
{
	queue<pair<ll, ll>> q;
	q.push({ 1, a });

	while (q.size())
	{
		ll now_idx = q.front().first, now_num = q.front().second;
		q.pop();

		if (now_num == b)
		{
			return now_idx;
		}

		if (now_num * 2 <= b)
		{
			q.push({ now_idx + 1, now_num * 2 });
		}

		if ((now_num * 10) + 1 <= b)
		{
			q.push({ now_idx + 1, (now_num * 10) + 1 });
		}
	}

	return -1;
}

int gready()
{
	int cnt = 1;

	while (a < b)
	{
		if (b % 10 == 1)
		{
			b /= 10;
		}
		else if (b % 2 == 0)
		{
			b /= 2;
		}
		else
		{
			return -1;
		}

		cnt++;
	}

	return b == a ? cnt : -1;
}

int main()
{
	cin >> a >> b;

	/*
	ll ret = go(1, a);

	cout << (ret == INT64_MAX ? -1 : ret) << "\n";
	

	cout << bfs(1) << "\n";
	*/

	cout << gready() << "\n";

	return 0;
}