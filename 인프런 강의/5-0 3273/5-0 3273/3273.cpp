#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, x, ret;
vector<int> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> x;

	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	while (l < r)
	{
		if (v[l] + v[r] == x) ret++, r--;
		else if (v[l] + v[r] < x) l++;
		else if (v[l] + v[r] > x) r--;
	}

	cout << ret << "\n";
	return 0;
}