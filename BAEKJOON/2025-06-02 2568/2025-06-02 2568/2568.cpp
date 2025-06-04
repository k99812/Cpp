#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>

using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> lis;
stack<pair<int, int>> s;

int main()
{
	cin >> n;

	v = vector<pair<int, int>>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	for (const pair<int, int>& i : v)
	{
		vector<int>::iterator itr = lower_bound(lis.begin(), lis.end(), i.second);
		int pos = itr - lis.begin();

		if (itr == lis.end())
		{
			lis.push_back(i.second);
		}
		else
		{
			lis[pos] = i.second;
		}

		s.push({ pos, i.first });
	}

	int len = lis.size();
	cout << n - len << "\n";
	len--;

	set<int> ret;
	while (s.size())
	{
		int pos = s.top().first;
		int val = s.top().second;

		if (pos != len)
		{
			ret.insert(val);
		}
		else
		{
			len--;
		}

		s.pop();
	}

	for (const int& i : ret)
	{
		cout << i << "\n";
	}

	return 0;
}