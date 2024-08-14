#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> p, m;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp > 0) p.push_back(temp);
		else m.push_back(temp);
	}

	sort(p.begin(), p.end());
	sort(m.begin(), m.end());

	int ret = 0;

	for (int i = p.size() - 1; i > 0; i -= 2)
	{
		if (p[i] == 1 || p[i - 1] == 1) ret += p[i] + p[i - 1];
		else ret += p[i] * p[i - 1];
	}

	for (int i = 0; i < (int)m.size() - 1; i += 2)
	{
		ret += m[i] * m[i + 1];
	}

	if (p.size() % 2) ret += p[0];
	if (m.size() % 2) ret += m[m.size() - 1];

	cout << ret << "\n";

	return 0;
}