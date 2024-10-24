#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

int n;
map<string, int> m;
vector<int> stack;

void init_code()
{
	m["push"] = 1,
		m["pop"] = 2,
		m["size"] = 3,
		m["empty"] = 4,
		m["top"] = 5;
}

int main()
{
	init_code();

	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;

		switch (m[s])
		{
		case 1:
			int num;
			cin >> num;
			stack.push_back(num);
			break;
		case 2:
			if (stack.size())
			{
				cout << stack.back() << "\n";
				stack.pop_back();
			}
			else
			{
				cout << -1 << "\n";
			}
			break;
		case 3:
			cout << stack.size() << "\n";
			break;
		case 4:
			cout << (stack.empty() ? 1 : 0) << "\n";
			break;
		case 5:
			if (stack.size())
			{
				cout << stack.back() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
			break;
		}
	}

	return 0;
}