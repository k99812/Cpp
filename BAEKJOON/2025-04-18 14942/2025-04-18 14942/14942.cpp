#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int n;
vector<int> energy;

int main()
{
	cin >> n;

	energy = vector<int>(n);
	
	for (int& i : energy)
	{
		cin >> i;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
	}

	return 0;
}