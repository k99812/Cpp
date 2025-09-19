#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}

	int ret = 0;
	while (pq.size() > 1)
	{
		int card_1 = pq.top();
		pq.pop();

		int card_2 = pq.top();
		pq.pop();

		int next = card_1 + card_2;
		ret += next;

		pq.push(next);
	}

	cout << ret << "\n";

	return 0;
}