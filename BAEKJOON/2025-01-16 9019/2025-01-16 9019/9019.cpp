#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

#define MOD 10000

using namespace std;

int Double(int a)
{
	return (a * 2) % MOD;
}

int Sub(int a)
{
	if (a) return a - 1;;
	return 9999;
}

int Left(int a)
{
	return (a % 1000) * 10 + (a / 1000);
}

int Right(int a)
{
	return a / 10 + (a % 10) * 1000;
}

string bfs(const int& a, const int& b)
{
	vector<int> visited(10004);
	queue<pair<int, string>> q;
	q.push({ a, "" });
	visited[a] = true;

	while (q.size())
	{
		int num = q.front().first;
		string oper = q.front().second;
		q.pop();

		if (num == b) return oper;

		for (int i = 0; i < 4; i++)
		{
			int next;
			string next_oper = oper;
			switch (i)
			{
				case 0:
					next = Double(num);
					next_oper.push_back('D');
					break;
				case 1:
					next = Sub(num);
					next_oper.push_back('S');
					break;
				case 2:
					next = Left(num);
					next_oper.push_back('L');
					break;
				case 3:
					next = Right(num);
					next_oper.push_back('R');
					break;
			}

			if (visited[next]) continue;

			visited[next] = true;
			q.push({ next, next_oper });
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int a, b;
		cin >> a >> b;

		cout << bfs(a, b) << "\n";
	}

	return 0;
}