#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int n;
vector<int> v, signal;

int main()
{
	cin >> n;

	v = signal = vector<int>(n);
	for (int& i : v)
	{
		cin >> i;
	}

	stack<pair<int, int>> st;

	for (int i = 0; i < n; i++)
	{
		while (st.size() && st.top().second <= v[i]) st.pop();

		if (st.size()) signal[i] = st.top().first + 1;

		st.push({ i, v[i] });
	}

	for (const int& i : signal)
	{
		cout << i << " ";
	}

	return 0;
}