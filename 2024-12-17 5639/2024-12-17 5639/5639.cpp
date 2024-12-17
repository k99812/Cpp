#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void go(int start, int end, const vector<int>& v)
{
	if (start >= end)
	{
		return;
	}

	int idx = start + 1;
	while (idx < end)
	{
		if (v[start] < v[idx]) break;
		idx++;
	}

	go(start + 1, idx, v);
	go(idx, end, v);
	cout << v[start] << "\n";
	return;
}

int main()
{
	int n;
	vector<int> v;

	while (cin >> n)
	{
		if (n == -1) break;
		v.push_back(n);
	}

	go(0, v.size(), v);

	return 0;
}