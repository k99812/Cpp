#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int T, n;
string p, nums;

int main()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		deque<int> ret;
		cin >> p >> n >> nums;

		int s = 0;
		for (char c : nums)
		{
			if (c == '[' || c == ']') continue;
			if ('0' <= c && c <= '9')
			{
				s = s * 10 + c - '0';
			}
			else
			{
				if (s > 0)
				{
					ret.push_back(s);
					s = 0;
				}
			}
		}
		if (s > 0) ret.push_back(s);

		bool error = false, rev = false;
		for (char c : p)
		{
			if (c == 'R') rev = !rev;
			else
			{
				if (ret.empty())
				{
					error = true;
					break;
				}
				if (rev) ret.pop_back();
				else ret.pop_front();
			}
		}

		if (error) cout << "error\n";
		else
		{
			cout << "[";
			if (rev) reverse(ret.begin(), ret.end());

			for (int i = 0; i < ret.size(); i++) 
			{
				cout << ret[i];
				if (i < ret.size() - 1) cout << ",";
			}
			cout << "]\n";
		}
	}

	return 0;
}