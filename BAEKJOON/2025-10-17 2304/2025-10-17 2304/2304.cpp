#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Cordi
{
	int y, x;

	bool operator<(const Cordi& other) const
	{
		return x < other.x;
	}
};

int n;
vector<Cordi> arr;

int main()
{
	cin >> n;

	arr = vector<Cordi>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr.begin(), arr.end());

	int max_h = 0, max_idx = 0;

	for (int i = 0; i < n; i++)
	{
		if (max_h < arr[i].y)
		{
			max_h = arr[i].y;
			max_idx = i;
 		}
	}

	int ret = 0, now_h = 0;

	for (int i = 0; i < max_idx; i++)
	{
		if (now_h < arr[i].y)
		{
			now_h = arr[i].y;
		}

		ret += (arr[i + 1].x - arr[i].x) * now_h;
	}

	now_h = 0;

	for (int i = n - 1; i > max_idx; i--)
	{
		if (now_h < arr[i].y)
		{
			now_h = arr[i].y;
		}

		ret += (arr[i].x - arr[i - 1].x) * now_h;
	}

	ret += max_h;

	cout << ret << "\n";

	return 0;
}