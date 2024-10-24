#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (!temp)
		{
			if (pq.size())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else
		{
			pq.push(temp);
		}
	}

	return 0;
}