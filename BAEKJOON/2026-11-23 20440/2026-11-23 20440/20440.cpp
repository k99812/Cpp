#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<pair<int, int>> times;

int main()
{
	cin >> n;
	times.reserve(2 * n);

	for (int i = 0; i < n; i++)
	{
		int in, out;
		cin >> in >> out;
		times.push_back({ in, 1 });
		times.push_back({ out, -1 });
	}

	sort(times.begin(), times.end());

	pair<int, int> ret = { 0, 0 };
	int cnt = 0, max_cnt = 0;
	bool isMax = false;

	for (int i = 0; i < (int)times.size(); )
	{
		int cur = times[i].first;

		while (i < (int)times.size() && times[i].first == cur)
		{
			cnt += times[i].second;
			i++;
		}

		if (cnt > max_cnt)
		{
			max_cnt = cnt;
			ret.first = cur;
			isMax = true;
		}
		else if (cnt < max_cnt && isMax)
		{
			ret.second = cur;
			isMax = false;
		}
	}

	cout << max_cnt << "\n" << ret.first << " " << ret.second << "\n";

	return 0;
}