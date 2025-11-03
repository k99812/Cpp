#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> crane, boxes;

bool comp(const int& a, const int& b)
{
	return a > b;
}

int gready()
{
	int time = 0;
	while (boxes.size())
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < boxes.size(); j++)
			{
				if (boxes[j] <= crane[i])
				{
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
		}

		time++;
	}
	return time;
}

bool canMove(int mid)
{
	vector<int> moves(n, mid);

	int idx = 0;

	for (int i = 0; i < m; i++)
	{
		bool flag = false;

		for (int j = 0; j < n; j++)
		{
			if (crane[j] >= boxes[i] && moves[j] > 0)
			{
				moves[j]--;
				flag = true;
				break;
			}
		}

		if (!flag) return false;
	}

	return true;
}

int main()
{
	cin >> n;

	crane = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> crane[i];
	}

	cin >> m;
	boxes = vector<int>(m);

	for (int i = 0; i < m; i++)
	{
		cin >> boxes[i];
	}

	sort(crane.begin(), crane.end(), comp);
	sort(boxes.begin(), boxes.end(), comp);

	if (boxes[0] > crane[0])
	{
		cout << -1 << "\n";
		return 0;
	}

	int low = 1, high = m, time = m;
	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (canMove(mid))
		{
			high = mid - 1;
			time = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	
	cout << time << "\n";

	return 0;
}