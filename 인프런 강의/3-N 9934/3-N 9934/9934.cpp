#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int k, temp;
vector<int> v;
vector<int> ret[14];

void inorder(int start, int end, int level)
{
	if (start >= end) return;

	int mid = (start + end) / 2;
	//cout << " start : " << start << " mid : " << mid <<" end : " << end << " level : " << level << "\n";
	ret[level].push_back(v[mid]);
	inorder(start, mid, level + 1);
	inorder(mid + 1, end, level + 1);
}

int main()
{
	cin >> k;

	for (int i = 0; i < (int)pow(2, k) - 1; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	inorder(0, (int)pow(2, k) - 1, 1);
	for (int i = 1; i <= k; i++)
	{
		for (int j : ret[i])
		{
			cout << j << " ";
		}
		cout << "\n";
	}

	return 0;
}