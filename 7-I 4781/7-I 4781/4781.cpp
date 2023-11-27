#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
float m;
vector<pair<int, float>> v(5004);

int go(int c, float p, int idx)
{
	//기저사례
	if (p > m) return -1e9;
	if (p == m) return 0;

	//메모리제이션
	int& ret;
	if (ret) return ret;

	//로직
	return ret += max(go(c, p), )

}

int main()
{
	while (cin >> n && cin >> m)
	{
		if (m == 0.00f) break;

		v.clear();

		for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

		
	}

	return 0;
}