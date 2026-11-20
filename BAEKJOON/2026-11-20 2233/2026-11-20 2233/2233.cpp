#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n, x, y;
	string s;

    cin >> n >> s >> x >> y;

	s = " " + s;

	vector<int> parent(n + 1, 0), depth(n + 1, 0);
	vector<int> in_pos(n + 1, 0), out_pos(n + 1, 0);       
	vector<int> pos_node(2 * n + 1);

	vector<int> st;
	int node_cnt = 0;

	for (int i = 1; i <= 2 * n; i++)
	{
		if (s[i] == '0')
		{
			int cur = ++node_cnt;
			int p = st.empty() ? 0 : st.back();

			parent[cur] = p;
			depth[cur] = (p == 0) ? 0 : depth[p] + 1;
			in_pos[cur] = i;
			pos_node[i] = cur;

			st.push_back(cur);
		}
		else
		{
			int cur = st.back();
			st.pop_back();

			out_pos[cur] = i;
			pos_node[i] = cur;
		}
	}

	int u = pos_node[x], v = pos_node[y];

	while (depth[u] > depth[v]) u = parent[u];
	while (depth[v] > depth[u]) v = parent[v];

	while (u != v)
	{
		u = parent[u];
		v = parent[v];
	}

	cout << in_pos[u] << " " << out_pos[u] << "\n";

	return 0;
}