#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, temp, len;
vector<int> v(100004);

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		vector<int>::iterator itr = lower_bound(v.begin(), v.begin() + len, temp);
		int pos = itr - v.begin();
		if (v[pos] == 0) len++;
		v[pos] = temp;
	}
	
	cout << n - len << "\n";

	return 0;
}