#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n, ret;
string str;
vector<int> v;

int main()
{
	cin >> n >> str;
	v.push_back(-1);

	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(') v.push_back(i);
		if (str[i] == ')')
		{
			v.pop_back();
			if (!v.empty())
			{
				ret = max(ret, i - v.back());
			}
			else
			{
				v.push_back(i);
			}
		}
	}

	cout << ret << "\n";
	return 0;
}