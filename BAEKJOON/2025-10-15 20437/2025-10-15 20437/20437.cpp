#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int INF = INT32_MAX;

int t;

int main()
{
	cin >> t;

	while (t--)
	{
		int k;
		string s;
		cin >> s >> k;

		vector<vector<int>> pos(26);
		for (int i = 0; i < s.size(); i++)
		{
			pos[s[i] - 'a'].push_back(i);
		}

		int min_len = INF, max_len = -1;

		for (int i = 0; i < 26; i++)
		{
			if (pos[i].size() < k) continue;

			for (int j = 0; j <= pos[i].size() - k; j++)
			{
				int start = pos[i][j], end = pos[i][j + k - 1];
				int len = end - start + 1;

				min_len = min(min_len, len);
				max_len = max(max_len, len);
			}
		}

		if (min_len == INF || max_len == -1)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << min_len << " " << max_len << "\n";
		}
	}

	return 0;
}