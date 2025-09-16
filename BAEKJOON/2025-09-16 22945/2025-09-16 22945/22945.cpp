#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v;

int main()
{
	cin >> n;
	v = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int left = 0, right = n - 1, ret = 0;
	while (left < right && (right - left - 1) > 0)
	{
		int left_num = v[left], right_num = v[right];
		int point = (right - left - 1) * min(left_num, right_num);
		ret = max(ret, point);

		if (left_num < right_num) left++;
		else right--;
	}

	cout << ret << "\n";

	return 0;
}