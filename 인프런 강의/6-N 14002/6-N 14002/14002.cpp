#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<stack>

using namespace std;

int n, num, len;
vector<pair<int, int>> pa;
stack<int> s;

int main()
{
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		vector<int>::iterator itr = lower_bound(v.begin(), v.begin() + len, num);
		int pos = itr - v.begin();
		if (v[pos] == 0) len++;
		v[pos] = num;
		pa.push_back({ pos, num });
	}

	cout << len << "\n";

	for (int i = n - 1; i >= 0; i--)
	{
		if (len - 1 == pa[i].first)
		{
			s.push(pa[i].second);
			len--;
		}
	}

	while (s.size())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}