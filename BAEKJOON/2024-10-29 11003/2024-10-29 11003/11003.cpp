#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 5000000 + 4

using namespace std;

int n, l, a[MAX_NUM];

int main()
{
	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++)
	{
		pq.push({ a[i], i });

		int pos = pq.top().second;

		while (pos < i - l + 1)
		{
			pq.pop();
			pos = pq.top().second;
		}

		cout << pq.top().first << " ";
	}

	return 0;
}