#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<string> star(5);

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> star[i];
	}

	n = 5, m = star[0].size();

	return 0;
}