#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int n, num, len;
vector<int> lis(1004);
vector<pair<int, int>> v;
stack<int> s;

int main()   
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		vector<int>::iterator itr = lower_bound(lis.begin(), lis.begin() + len, num);
		int pos = itr - lis.begin();
		if (lis[pos] == 0) len++;
		lis[pos] = num;
		v.push_back({ pos, num });
	}

	cout << len << "\n";

	for (int i = n - 1; i >= 0; i--)
	{
		if (len - 1 == v[i].first)
		{
			len--;
			s.push(v[i].second);
		}
	}

	while (s.size())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}