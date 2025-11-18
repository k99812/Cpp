#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int d, p;
ll ret = -1;
map<pair<int, int>, bool> visited;

int getLength(ll num)
{
	if (num == 0) return 1;

	int cnt = 0;
	while (num > 0)
	{
		cnt++;
		num /= 10;
	}
	return cnt;
}

void go(ll num, int cnt)
{
	if (cnt == p && getLength(num) <= d)
	{
		ret = max(ret, num);
		return;
	}

	for (int i = 2; i <= 9; i++)
	{
		ll next = num * i;
		int next_cnt = cnt + 1;

		if (getLength(next) > d || next_cnt > p) continue;
		if (visited[{next, next_cnt}]) continue;

		visited[{next, next_cnt}] = true;
		go(next, next_cnt);
	}
}

int main()
{
	cin >> d >> p;

	go(1, 0);

	cout << ret << "\n";

	return 0;
}