#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>

using namespace std;

int T, n, m;

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n >> m;

		deque<pair<int, int>> deq(n);
		priority_queue<int> pq;

		for (int i = 0; i < n; i++)
		{
			int p;
			cin >> p;

			deq[i] = { p, i };
			pq.push(p);
		}
		
		int printed = 0;
		while (deq.size())
		{
			const pair<int, int> now = deq.front();
			deq.pop_front();

			if (now.first == pq.top())
			{
				printed++;
				pq.pop();

				if (now.second == m)
				{
					cout << printed << "\n";
					break;
				}
			}
			else
			{
				deq.push_back(now);
			}
		}
	}

	return 0;
}