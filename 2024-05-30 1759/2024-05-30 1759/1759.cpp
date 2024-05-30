#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
char a[20];
vector<char> v;

bool check()
{
	int vowCnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == 'a' || v[i] == 'e'|| v[i] == 'i'|| v[i] == 'o'|| v[i] == 'u')
		{
			vowCnt++;
		}
	}

	if (vowCnt >= 1 && n - vowCnt >= 2) return true;
	return false;
}

void go(int idx)
{
	if (v.size() == n)
	{
		if (check())
		{
			for (char i : v)
			{
				cout << i;
			}
			cout << "\n";
		}
		return;
	}

	for (int i = idx + 1; i < m; i++)
	{
		v.push_back(a[i]);
		go(i);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	sort(a, a + m);
	go(-1);

	return 0;
}