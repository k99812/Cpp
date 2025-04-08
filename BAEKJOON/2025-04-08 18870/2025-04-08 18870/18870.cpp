#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int n;
vector<int> cordi;

int main()
{
	cin >> n;

	cordi = vector<int>(n);

	for (int& i : cordi)
	{
		cin >> i;
	}

	vector<int> v(cordi);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	unordered_map<int, int> map;
	for (int i = 0; i < v.size(); i++)
	{
		map[v[i]] = i;
	}

	for (int i = 0; i < n; i++)
	{
		cout << map[cordi[i]] << " ";
	}

	/*
	for(const int& i:cordi)
	{
		int pos = lower_bound(v.begin(), v.end(), i) - v.begin();

		cout << pos << " ";
	}
	*/

	return 0;
}