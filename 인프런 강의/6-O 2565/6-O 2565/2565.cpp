#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, a, b, len;
vector<pair<int, int>> v;
vector<int> lis(504);

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		vector<int>::iterator itr = lower_bound(lis.begin(), lis.begin() + len, v[i].second);
		int pos = itr - lis.begin();
		if (lis[pos] == 0) len++;
		lis[pos] = v[i].second;
		cout << "num : " << v[i].second << "  pos : " << pos << "\n";
	}
	for (int i = 0; i < len; i++) cout << lis[i] << " ";
	cout << "\n";
	cout << n - len << "\n";
	return 0;
}