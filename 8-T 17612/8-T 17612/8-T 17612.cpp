#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Casher
{
	int id, max_time, casher_id;
};

struct comp
{
	bool operator()(Casher& a, Casher& b)
	{
		if (a.max_time == b.max_time)
		{
			return a.casher_id > b.casher_id;
		}

		return  a.max_time > b.max_time;
	}
};

bool comp2(const Casher& a, const Casher& b)
{
	if (a.max_time == b.max_time)
	{
		return a.casher_id > b.casher_id;
	}

	return a.max_time < b.max_time;
}

int n, k, id, cost, idx;
long long ret;
vector<Casher> v;
priority_queue<Casher, vector<Casher>, comp> pq;

int main()
{
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		cin >> id >> cost;

		if (i < k)
		{
			pq.push({ id, cost, i + 1 });
			continue;
		}
		pq.push({ id, cost + pq.top().max_time, pq.top().casher_id });
		v.push_back(pq.top());
		pq.pop();
	}

	while (pq.size())
	{
		v.push_back(pq.top());
		pq.pop();
	}

	sort(v.begin(), v.end(), comp2);

	for (int i = 0; i < v.size(); i++)
	{
		ret += 1LL * (i + 1) * v[i].id;
	}

	cout << ret << "\n";

	return 0;
}