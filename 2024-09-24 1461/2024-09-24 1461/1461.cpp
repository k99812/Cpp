#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_NUM 50 + 4

using namespace std;

int n, m, ret, MAX = -1;
vector<int> pos, neg;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		temp < 0 ? neg.push_back(temp) : pos.push_back(temp);
	}

	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());

	for (int i = 0; i < neg.size(); i += m)
	{
		ret += abs(neg[i]) * 2;
		MAX = max(MAX, abs(neg[i]));
	}

	for (int i = pos.size() - 1; i >= 0; i -= m)
	{
		ret += pos[i] * 2;
		MAX = max(MAX, pos[i]);
	}

	ret -= MAX;

	cout << ret << "\n";

	return 0;
} 