#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int INF = 1e9;

int n;
vector<string> original;
vector<pair<string, int>> v;

int getLength(const string& a, const string& b)
{
	int len = 0;
	int size = min(a.size(), b.size());
	for (int i = 0; i < size; i++)
	{
		if (a[i] == b[i]) len++;
		else break;
	}

	return len;
}

int main()
{
	cin >> n;

	original = vector<string>(n);
	v = vector<pair<string, int>>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
		original[i] = v[i].first;
	}

	sort(v.begin(), v.end());

	int max_len = -1, first = INF, second = INF;
	for (int i = 0; i < n - 1; i++) 
	{
		max_len = max(max_len, getLength(v[i].first, v[i + 1].first));
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (getLength(v[i].first, v[i + 1].first) < max_len) continue;

		for (int j = i + 1; j < n; j++)
		{
			int now_len = getLength(v[i].first, v[j].first);

			if (now_len < max_len) break;

			int now_first = min(v[i].second, v[j].second);
			int now_second = max(v[i].second, v[j].second);

			if (now_first < first)
			{
				first = now_first, second = now_second;
			}
			else if (first == now_first && now_second < second)
			{
				second = now_second;
			}
		}
	}

	cout << original[first] << "\n" << original[second] << "\n";

	return 0;
}