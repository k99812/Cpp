#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int m;
vector<pair<int, int>> lines;

int main()
{
	cin >> m;

	int a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0) break;

		if (a > b) swap(a, b);
		lines.push_back({ a, b });
	}

	sort(lines.begin(), lines.end());

	int cur = 0, idx = 0, cnt = 0;
	while (cur < m)
	{
		int max_end = 0, found = 0;

		while (idx < lines.size() && lines[idx].first <= cur)
		{
			if (max_end < lines[idx].second)
			{
				max_end = lines[idx].second;
			}

			idx++;
			found = true;
		}

		if (!found || max_end <= cur)
		{
			cout << 0 << "\n";
			return 0;
		}

		cur = max_end;
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}