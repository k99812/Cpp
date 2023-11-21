#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

long long n, k, temp, temp2, ret;
vector<long long> c;
vector<pair<long long, long long>> mv;
priority_queue<long long> pq;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> temp >> temp2;
		mv.push_back({ temp, temp2 });
	}

	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		c.push_back(temp);
	}

	sort(mv.begin(), mv.end());
	sort(c.begin(), c.end());

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && mv[j].first <= c[i]) pq.push(mv[j++].second);
		if (pq.size())
		{
			ret += pq.top(); pq.pop();
		}
	}
	
	cout << ret << "\n";
	return 0;
}