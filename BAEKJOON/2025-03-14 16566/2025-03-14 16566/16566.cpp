#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, k;

int main()
{
	cin >> n >> m >> k;

	vector<int> card(m + 1), opp(k + 1);

	for (int& i : card)
	{
		cin >> i;
	}

	for (int& i : opp)
	{
		cin >> i;
	}

	return 0;
}