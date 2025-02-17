#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

vector<ll> v;

void go(ll num, int last)
{
	v.push_back(num);

	for (int i = last - 1; i >= 0; i--)
	{
		go(num * 10 + i, i);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
	{
		go(i, i);
	}

	sort(v.begin(), v.end());

	cout << (n >= v.size() ? -1 : v[n]) << "\n";

	return 0;
}