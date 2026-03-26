#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int v, e, id_cnt;
vector<vector<int>> graph, SCC;
vector<int> finished, id;
stack<int> s;

int dfs(int now)
{
	id[now] = ++id_cnt;
	s.push(now);

	int parent = id[now];

	for (const int next : graph[now])
	{
		if (id[next] == 0)
		{
			parent = min(parent, dfs(next));
		}
		else if (!finished[next])
		{
			parent = min(parent, id[next]);
		}
	}

	if (id[now] == parent)
	{
		vector<int> scc;

		while (true)
		{
			int top = s.top();
			s.pop();
			scc.push_back(top);
			finished[top] = true;

			if (top == now) break;
		}

		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}

	return parent;
}

int main()
{
	cin >> v >> e;

	graph.assign(v + 1, vector<int>());
	finished.assign(v + 1, 0);
	id.assign(v + 1, 0);

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
	}

	for (int i = 1; i <= v; i++)
	{
		if (id[i] == 0)
		{
			dfs(i);
		}
	}

	sort(SCC.begin(), SCC.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[0] < b[0];
	});

	cout << SCC.size() << "\n";
	for (const vector<int>& v : SCC)
	{
		for (const int i : v)
		{
			cout << i << " ";
		}
		cout << "-1\n";
	}

	return 0;
}