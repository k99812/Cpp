#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

long long n, k, m, v, c, ret;
vector<pair<long long, long long>> jems;
vector<long long> Cs;
priority_queue<long long> pq;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		jems.push_back({ m, v });
	}

	for (int i = 0; i < k; i++)
	{
		cin >> c;
		Cs.push_back(c);
	}

	sort(jems.begin(), jems.end());
	sort(Cs.begin(), Cs.end());

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && Cs[i] >= jems[j].first)
		{
			pq.push(jems[j].second);
			j++;
		}

		if (pq.size())
		{
			ret += pq.top(); pq.pop();
		}
	}

	cout << ret << "\n";

	return 0;
}