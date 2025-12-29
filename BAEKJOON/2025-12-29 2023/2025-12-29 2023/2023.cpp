#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> first = { 2, 3, 5, 7 };
vector<int> next_num = { 1, 3, 7, 9 };

bool isPrim(int num)
{
	if (num < 2) return false;

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}

void go(int idx, int now)
{
	if (idx == n)
	{
		cout << now << "\n";

		return;
	}

	for (const int i : next_num)
	{
		int next = now * 10 + i;

		if (!isPrim(next)) continue;

		go(idx + 1, next);
	}
}

int main()
{
	cin >> n;

	for (const int i : first)
	{
		go(1, i);
	}

	return 0;
}