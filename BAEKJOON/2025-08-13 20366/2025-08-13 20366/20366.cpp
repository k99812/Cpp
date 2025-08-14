#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Info
{
	int sum, first, second;

	bool operator<(const Info& other) const
	{
		return sum < other.sum;
	}
};

int n;
vector<int> arr;

int main()
{
	cin >> n;

	arr = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	vector<Info> sums;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sums.push_back({ arr[i] + arr[j], i, j });
		}
	}

	sort(sums.begin(), sums.end());

	int min_num = INT32_MAX;

	for (int i = 0; i < sums.size(); i++)
	{
		for (int j = i + 1; j < sums.size(); j++)
		{
			Info& snowman_1 = sums[i];
			Info& snowman_2 = sums[j];

			if (snowman_1.first != snowman_2.first && snowman_1.first != snowman_2.second &&
				snowman_1.second != snowman_2.first && snowman_1.second != snowman_2.second)
			{
				min_num = min(min_num, snowman_2.sum - snowman_1.sum);

				break;
			}
		}
	}

	cout << min_num << "\n";

	return 0;
}