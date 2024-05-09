#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n, s, t;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int go()
{
	pq.push(v[0].second);

	for (int i = 1; i < n; i++)
	{
		pq.push(v[i].second);

		if (pq.top() <= v[i].first) pq.pop();
	}

	return pq.size();
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		v.push_back({ s, t });
	}

	sort(v.begin(), v.end());

	cout << go() << "\n";

	return 0;
}