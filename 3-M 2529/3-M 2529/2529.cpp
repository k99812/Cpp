#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int k, visited[10];
char c;
vector<char> op;
vector<string> ret;

bool check(char first, char second, char oper)
{
	if (oper == '<') return first < second;
	if (oper == '>') return first > second;
}

void dfs(int idx, string num)
{
	if (idx == k + 1)
	{
		ret.push_back(num);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (visited[i]) continue;
		if (idx == 0 || check(num[idx - 1], i + '0', op[idx - 1]))
		{
			visited[i] = 1;
			dfs(idx + 1, num + to_string(i));
			visited[i] = 0;
		}
	}
	return;
}

int main()
{
	cin >> k;
	
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		op.push_back(c);
	}

	dfs(0, "");
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
	return 0;
}