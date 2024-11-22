#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Info
{
	int ClassNum,
		StartTime,
		EndTime;
};

int n, ret = 1;

bool comp(const Info& a, const Info& b)
{
	if (a.StartTime == b.StartTime)
	{
		if (a.EndTime == b.EndTime)
		{
			return a.ClassNum < b.ClassNum;
		}

		return a.EndTime < b.EndTime;
	}

	return a.StartTime < b.StartTime;
}

int main()
{
	cin >> n;
	vector<Info> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].ClassNum >> v[i].StartTime >> v[i].EndTime;
	}

	sort(v.begin(), v.end(), comp);

	priority_queue<int, vector<int>, greater<int>> pq;

	for (const Info& now : v)
	{
		if (pq.size())
		{
			if (pq.top() > now.StartTime)
			{
				ret++;
			}
			else
			{
				pq.pop();
			}
		}

		pq.push(now.EndTime);
	}

	cout << ret << "\n";

	return 0;
}