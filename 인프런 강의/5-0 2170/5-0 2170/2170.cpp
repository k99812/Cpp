#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n, from, to, ret, l, r;
pair<int, int> L[1000004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		L[i] = {from, to};
	}

	sort(L, L + n);
	l = L[0].first; r = L[0].second;

	for (int i = 1; i < n; i++)
	{
		if (r < L[i].first)
		{
			ret += (r - l);
			l = L[i].first;
			r = L[i].second;
		}
		else if (L[i].first <= r && r <= L[i].second)
		{
			r = L[i].second;
		}
	}
	ret += (r - l);
	cout << ret << "\n";
	return 0;
}