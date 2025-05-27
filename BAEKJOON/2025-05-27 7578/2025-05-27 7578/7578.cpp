#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> A, B, segTree;

int main()
{
	cin >> n;

	A = B = vector<int>(n);
	segTree = vector<int>(4 * n);

	for (int& i : A)
	{
		cin >> i;
	}

	for (int& i : B)
	{
		cin >> i;
	}

	return 0;
}