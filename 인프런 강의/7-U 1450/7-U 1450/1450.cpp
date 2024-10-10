#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
ll n, c, a[34], ret;
vector<int> v, v2;

void go(int idx, int last, vector<int>& InVector, int w)
{
	if (w > c) return;
	
	if (idx > last)
	{
		InVector.push_back(w);
		return;
	}

	go(idx + 1, last, InVector, w + a[idx]);
	go(idx + 1, last, InVector, w);
	return;
}

int main()
{
	cin >> n >> c;

	for (int i = 0; i < n; i++) cin >> a[i];

	go(0, n / 2 - 1, v, 0);
	go(n / 2, n - 1, v2, 0);

	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	for (int i : v)
	{
		if (c - i >= 0) ret += (int)(upper_bound(v2.begin(), v2.end(), c - i) - v2.begin());
	}

	cout << ret << "\n";

	return 0;
}