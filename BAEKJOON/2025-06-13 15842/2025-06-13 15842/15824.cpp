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

	for (int& i : v)
	{
		cin >> i;
	}

	return 0;
}