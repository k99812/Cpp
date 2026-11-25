#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>

using namespace std;

enum query
{
	add = 1,
	solved,
	recommend,
	recommend2,
	recommend3
};

struct Node
{
	int idx, l, g;

	bool operator<(const Node& other) const
	{
		if (l == other.l) return idx < other.idx;
		return l < other.l;
	}
};

int n, m;
set<Node> allSet;
unordered_map<int, set<Node>> groupSet;
unordered_map<int, Node> info_mp;
unordered_map<string, query> mp;

int main()
{
	mp["add"] = query::add;
	mp["solved"] = query::solved;
	mp["recommend"] = query::recommend;
	mp["recommend2"] = query::recommend2;
	mp["recommend3"] = query::recommend3;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		Node node;
		cin >> node.idx >> node.l >> node.g;

		allSet.insert(node);
		groupSet[node.g].insert(node);
		info_mp[node.idx] = node;
	}

	cin >> m;
	for (int k = 0; k < m; k++)
	{
		string s;
		cin >> s;

		switch (mp[s])
		{
		case query::add:
		{
			Node node;
			cin >> node.idx >> node.l >> node.g;

			allSet.insert(node);
			groupSet[node.g].insert(node);
			info_mp[node.idx] = node;
			break;
		}
		case query::solved:
		{
			int idx;
			cin >> idx;

			Node target = info_mp[idx];
			allSet.erase(target);
			groupSet[target.g].erase(target);

			break;
		}
		case query::recommend:
		{
			int g, x;
			cin >> g >> x;

			if (x == 1) cout << groupSet[g].rbegin()->idx << "\n";
			else cout << groupSet[g].begin()->idx << "\n";
			break;
		}
		case query::recommend2:
		{
			int x;
			cin >> x;

			if (x == 1) cout << allSet.rbegin()->idx << "\n";
			else cout << allSet.begin()->idx << "\n";
			break;
		}
		case query::recommend3:
		{
			int x, l;
			cin >> x >> l;

			auto itr = allSet.lower_bound({ 0, l, 0 });

			if (x == 1)
			{
				if (itr == allSet.end()) cout << -1 << "\n";
				else cout << itr->idx << "\n";
			}
			else
			{
				if (itr == allSet.begin()) cout << -1 << "\n";
				else cout << prev(itr)->idx << "\n";
			}

			break;
		}
		}
	}

	return 0;
}