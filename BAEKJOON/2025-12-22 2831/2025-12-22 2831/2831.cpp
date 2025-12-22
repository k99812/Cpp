#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int go(const vector<int>& taller, const vector<int>& smaller)
{
	int first = 0, second = 0, cnt = 0;

	while (first < taller.size() && second < smaller.size())
	{
		if (taller[first] < smaller[second])
		{
			cnt++, first++, second++;
		}
		else
		{
			second++;
		}
	}

	return cnt;
}

int main()
{
	cin >> n;

	vector<int> man_plus, man_minus, girl_plus, girl_minus;

	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;

		if (h > 0) man_plus.push_back(h);
		else man_minus.push_back(abs(h));
	}

	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;

		if (h > 0) girl_plus.push_back(h);
		else girl_minus.push_back(abs(h));
	}

	sort(man_plus.begin(), man_plus.end());
	sort(man_minus.begin(), man_minus.end());
	sort(girl_plus.begin(), girl_plus.end());
	sort(girl_minus.begin(), girl_minus.end());

	int ret = 0;

	ret += go(man_plus, girl_minus);
	ret += go(girl_plus, man_minus);

	cout << ret << "\n";

	return 0;
}