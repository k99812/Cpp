#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

using namespace std;

string str;
set<string> ret;
vector<bool> is_removed;
vector<pair<int, int>> arr;

void dfs(int idx, int cnt)
{
	if (idx == arr.size())
	{
		if (cnt > 0)
		{
			string temp = "";
			for (int i = 0; i < str.size(); i++)
			{
				if (!is_removed[i]) temp += str[i];
			}

			ret.insert(temp);
		}

		return;
	}

	is_removed[arr[idx].first] = true;
	is_removed[arr[idx].second] = true;
	dfs(idx + 1, cnt + 1);

	is_removed[arr[idx].first] = false;
	is_removed[arr[idx].second] = false;
	dfs(idx + 1, cnt);
}

int main()
{
	cin >> str;

	is_removed.assign(str.size(), false);
	vector<int> stack;

	for(int i=0; i<str.size(); i++)
	{
		if (str[i] == '(')
		{
			stack.push_back(i);
		}
		else if (str[i] == ')')
		{
			arr.push_back({ stack.back(), i });
			stack.pop_back();
		}
	}

	dfs(0, 0);

	for (const string& s : ret)
	{
		cout << s << "\n";
	}

	return 0;
}