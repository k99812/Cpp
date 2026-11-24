#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string t, p;

vector<int> getPi()
{
	int m = p.size();
	vector<int> pi(m, 0);

	int j = 0;
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
		{
			j = pi[j - 1];
		}

		if (p[i] == p[j])
		{
			pi[i] = ++j;
		}
	}

	return pi;
}

vector<int> kmp()
{
	vector<int> ret;
	vector<int> pi = getPi();

	int n = t.size();
	int m = p.size();

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && t[i] != p[j])
		{
			j = pi[j - 1];
		}

		if (t[i] == p[j])
		{
			if (j == m - 1)
			{
				ret.push_back(i - m + 2);
				j = pi[j];
			}
			else
			{
				j++;
			}
		}
	}

	return ret;
}

int main()
{
	getline(cin, t);
	getline(cin, p);

	vector<int> ret = kmp();

	cout << ret.size() << "\n";
	for (int pos : ret)
	{
		cout << pos << " ";
	}
	cout << "\n";

	return 0;
}