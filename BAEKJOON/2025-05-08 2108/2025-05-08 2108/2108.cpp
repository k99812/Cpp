#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int n;
vector<int> num;
map<int, int> m;

int freq()
{
	int max_num = 0;
	for (const pair<int, int>& i : m) 
	{
		if (i.second > max_num)
		{
			max_num = i.second;
		}
	}

	vector<int> temp;
	for (const pair<int, int>& i : m)
	{
		if (i.second == max_num)
		{
			temp.push_back(i.first);
		}
	}

	if (temp.size() == 1)
	{
		return temp[0];
	}
	
	sort(temp.begin(), temp.end());
	return temp[1];
}

int main()
{
	cin >> n;

	num = vector<int>(n);

	int sum = 0;
	for (int& i : num)
	{
		cin >> i;

		m[i]++;
		sum += i;
	}

	sort(num.begin(), num.end());

	cout << (int)round((double)sum / n) << "\n";

	cout << num[n / 2] << "\n";

	cout << freq() << "\n";

	cout << num[n - 1] - num[0] << "\n";

	return 0;
}