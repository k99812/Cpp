#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int len = 0;
	vector<int> lis(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		vector<int>::iterator itr = lower_bound(lis.begin(), lis.begin() + len, temp);
		int pos = itr - lis.begin();
		if (!lis[pos]) len++;
		lis[pos] = temp;
	}

	cout << n - len << "\n";

	return 0;
}