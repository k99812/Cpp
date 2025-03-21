#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<pair<long long, long long>> cordi;

double go()
{
	long long sum1 = 0, sum2 = 0;

	for (int i = 0; i < n; i++)
	{
		int next = (i + 1) % n;
		sum1 += cordi[i].first * cordi[next].second;
		sum2 += cordi[i].second * cordi[next].first;
	}

	return abs(sum1 - sum2) / 2.0;
}

int main()
{
	cin >> n;

	cordi.resize(n);

	for (pair<long long, long long>& itr : cordi)
	{
		cin >> itr.first >> itr.second;
	}

	cout << fixed;
	cout.precision(1);

	cout << go() << "\n";

	return 0;
}