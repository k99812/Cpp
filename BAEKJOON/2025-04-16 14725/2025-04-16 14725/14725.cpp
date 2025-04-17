#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

int n;

class Ant
{
private:
	map<string, Ant*> child;

public:
	void insert(int idx, vector<string>& foods)
	{
		if (idx == foods.size())
		{
			return;
		}

		//map.find로 검색시 itr가 end가 되면 데이터가 없는것
		if (child.find(foods[idx]) == child.end())
		{
			child[foods[idx]] = new Ant();
		}
		child[foods[idx]]->insert(idx + 1, foods);
	}

	void print(int idx)
	{
		for (const pair<string, Ant*>& c : child)
		{
			for (int i = 0; i < idx; i++)
			{
				cout << "--";
			}
			cout << c.first << "\n";
			c.second->print(idx + 1);
		}
	}
};

int main()
{
	cin >> n;

	Ant root;
	while (n--)
	{
		int k;
		cin >> k;

		vector<string> v(k);
		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
		}

		root.insert(0, v);
	}

	root.print(0);

	return 0;
}