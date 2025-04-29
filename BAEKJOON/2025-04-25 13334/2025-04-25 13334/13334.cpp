#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, d;

int main()
{
	cin >> n;

	vector<pair<int, int>> people;
	for (int i = 0; i < n; i++)
	{
		int from, to;
		cin >> from >> to;
		if (from > to) swap(from, to);
		people.push_back({ from, to });
	}

	cin >> d;

	sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	priority_queue<int, vector<int>, greater<int>> pq;
	int ret = 0;

	for (const pair<int, int>& i : people)
	{
		int from = i.first, to = i.second;
		int dist = to - from;

		if (dist > d) continue;

		pq.push(from);

		while (pq.size() && to - d > pq.top())
		{
			pq.pop();
		}

		ret = max(ret, (int)pq.size());
	}

	cout << ret << "\n";

	return 0;
}