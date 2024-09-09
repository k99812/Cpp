#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 1000 + 4

using namespace std;

int a[MAX_NUM], n, w, l, Time, total;
queue<int> bridge;

int main()
{
	cin >> n >> w >> l;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			if (bridge.size() == w)
			{
				total -= bridge.front();
				bridge.pop();
			}

			if (total + a[i] <= l) break;
			bridge.push(0);
			Time++;
		}
		bridge.push(a[i]);
		total += a[i];
		Time++;
	}

	cout << Time + w << "\n";

	return 0;
}