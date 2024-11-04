#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n;
priority_queue<int> pq_max;
priority_queue<int, vector<int>, greater<int>> pq_min;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (pq_max.empty())
		{
			pq_max.push(temp);
		}
		else if (pq_max.size() == pq_min.size())
		{
			pq_max.push(temp);
		}
		else
		{
			pq_min.push(temp);
		}
		
		if (pq_max.size() && pq_min.size() && pq_max.top() > pq_min.top())
		{
			int minNum = pq_min.top(), maxNum = pq_max.top();
			pq_min.pop(), pq_max.pop();

			pq_max.push(minNum);
			pq_min.push(maxNum);
		}

		cout << pq_max.top() << "\n";
	}

	return 0;
}