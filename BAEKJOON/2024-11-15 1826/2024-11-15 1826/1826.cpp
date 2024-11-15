#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, l, p, ret;

int main()
{
	cin >> n;
	vector<pair<int, int>> gas(n);

	for (int i = 0; i < n; i++)
	{
		cin >> gas[i].first >> gas[i].second;
	}

	cin >> l >> p;

	sort(gas.begin(), gas.end());

	priority_queue<int> pq;
	int pos = 0;

	while (p < l)
	{
		while (pos < n && gas[pos].first <= p)
		{
			pq.push(gas[pos++].second);
		}

		if (pq.empty())
		{
			ret = -1;
			break;
		}

		p += pq.top();
		pq.pop();
		ret++;
	}

	cout << ret << "\n";

	return 0;
}