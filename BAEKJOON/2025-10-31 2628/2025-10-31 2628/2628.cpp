#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, k;

int main()
{
	cin >> n >> m >> k;

	vector<int> horison, vertical;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a) vertical.push_back(b);
		else horison.push_back(b);
	}

	horison.push_back(0), vertical.push_back(0);
	horison.push_back(m), vertical.push_back(n);

	sort(horison.begin(), horison.end());
	sort(vertical.begin(), vertical.end());

	int max_y = 0, max_x = 0;
	for (int i = 0; i < horison.size() - 1; i++)
	{
		max_y = max(max_y, horison[i + 1] - horison[i]);
	}

	for (int i = 0; i < vertical.size() - 1; i++)
	{
		max_x = max(max_x, vertical[i + 1] - vertical[i]);
	}

	int ret = max_y * max_x;
	cout << ret << "\n";

	return 0;
}