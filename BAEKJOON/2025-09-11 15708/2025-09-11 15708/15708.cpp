#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

ll n, t, p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> t >> p;

	ll sum = 0;
	int cnt = 0, ret = 0;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		if (t - p * i < 0) break;

		int k;
		cin >> k;

		sum += k;
		pq.push(k);
		cnt++;

		while (sum + p * i > t)
		{
			sum -= pq.top();
			pq.pop();
			cnt--;
		}

		ret = max(ret, cnt);
	}

	cout << ret << "\n";
	
	return 0;
}