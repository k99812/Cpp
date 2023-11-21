#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int n, a[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> stk;
const int INF = 1e9 + 4;

int main()
{
	cin >> n;
	fill(a, a + 1000004, INF);
	
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		int* lowerPos = lower_bound(a, a + len, num);
		int pos = (int)(lower_bound(a, a + len, num) - a);
		if (*lowerPos == INF) len++;
		*lowerPos = num;
		ans[i].first = pos;
		ans[i].second = num;
	}

	cout << len << "\n";

	for (int i = n - 1; i >= 0; i--)
	{
		if (ans[i].first == len - 1)
		{
			stk.push(ans[i].second);
			len--;
		}
	}

	while (stk.size())
	{
		cout << stk.top() << " ";
		stk.pop();
	}

	return 0;
}