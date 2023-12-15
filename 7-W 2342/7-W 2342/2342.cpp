#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v;

int main()
{
	while (cin >> n)
	{
		if (n == 0) break;

		v.push_back(n);
	}

	return 0;
}