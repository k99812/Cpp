#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;

int main()
{
	cin >> n;

	ll left = 1, right = 2;
	bool found = false;

	while (left < right)
	{
		ll diff = right * right - left * left;

		if (diff == n)
		{
			cout << right << "\n";
			found = true;
			right++;
		}
		else if (diff < n)
		{
			right++;
		}
		else
		{
			left++;
		}
	}

	if (!found) cout << -1 << "\n";

	return 0;
}