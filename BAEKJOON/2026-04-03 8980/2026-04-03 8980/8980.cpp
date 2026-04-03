#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Info
{
	int from, to, num;

	bool operator<(const Info& other) const
	{
		if (to != other.to) return to < other.to;
		return from < other.from;
	}
};

int n, m, c;
vector<Info> arr;
vector<int> capacity;

int main()
{
	cin >> n >> c >> m;

	for (int i = 0; i < m; i++)
	{
		Info info;
		cin >> info.from >> info.to >> info.num;
		arr.push_back(info);
	}

	sort(arr.begin(), arr.end());

	capacity.assign(n + 1, 0);
	int ret = 0;
	
	for (const Info& info : arr)
	{
		int max_load = 0;

		for (int i = info.from; i < info.to; i++)
		{
			max_load = max(max_load, capacity[i]);
		}

		int can_load = min(info.num, c - max_load);

		for (int i = info.from; i < info.to; i++)
		{
			capacity[i] += can_load;
		}

		ret += can_load;
	}

	cout << ret << "\n";

	return 0;
}