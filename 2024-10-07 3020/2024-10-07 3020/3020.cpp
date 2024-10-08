#include<iostream>
#include<algorithm>
#include<vector>

#define INF 1e9

using namespace std;

int n, h, ret = INF, cnt;
vector<int> ground, ceiling;

int main()
{
	cin >> n >> h;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (i % 2)
		{
			ceiling.push_back(temp);
		}
		else
		{
			ground.push_back(temp);
		}
	}

	sort(ground.begin(), ground.end());
	sort(ceiling.begin(), ceiling.end());

	for (int i = 1; i <= h; i++)
	{
		int groundIdx = lower_bound(ground.begin(), ground.end(), i) - ground.begin();
		int ceilingIdx = upper_bound(ceiling.begin(), ceiling.end(), h - i) - ceiling.begin();
		int mid = n - (groundIdx + ceilingIdx);

		if (mid < ret)
		{
			ret = mid;
			cnt = 1;
		}
		else if (mid == ret) cnt++;
	}

	cout << ret << " " << cnt << "\n";

	return 0;
}