#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, num, len;


int main()
{
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		vector<int>::iterator temp = lower_bound(v.begin(), v.begin() + len, num);
		int pos = temp - v.begin();
		if (v[pos] == 0) len++;
		v[pos] = num;
	}

	cout << len << "\n";

	return 0;
}