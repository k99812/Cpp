#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

using namespace std;

struct Trie
{
	Trie* child[26];
	bool isEnd;

	Trie()
	{
		isEnd = false;
		fill(child, child + 26, nullptr);
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
		{
			if (child[i]) delete child[i];
		}
	}

public:
	void insert(Trie* root, const string& str)
	{
		Trie* cur = root;
		for (char c : str)
		{
			int idx = c - 'A';
			if (!cur->child[idx])
			{
				cur->child[idx] = new Trie();
			}
			cur = cur->child[idx];
		}
		cur->isEnd = true;
	}
};

const int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int score_board[] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };

int w, b;
vector<vector<bool>> visited;
vector<string> board;
set<string> founded;

void dfs(int y, int x, Trie* node, string str)
{
	if (node->isEnd) founded.insert(str);
	if (str.size() == 8) return;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
		if (visited[ny][nx]) continue;

		char next_c = board[ny][nx];
		int next_idx = next_c - 'A';

		if (node->child[next_idx])
		{
			visited[ny][nx] = true;
			dfs(ny, nx, node->child[next_idx], str + next_c);
			visited[ny][nx] = false;
		}
	}
}

int main()
{
	cin >> w;

	Trie* root = new Trie();

	for (int i = 0; i < w; i++)
	{
		string s;
		cin >> s;
		root->insert(root, s);
	}

	cin >> b;

	board.assign(4, "");

	while (b--)
	{
		founded.clear();

		for (int i = 0; i < 4; i++)
		{
			cin >> board[i];
		}
		
		visited.assign(4, vector<bool>(4, false));

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				char c = board[i][j];
				int idx = c - 'A';
				
				if (root->child[idx])
				{
					visited[i][j] = true;
					string temp = "";
					temp += c;
					dfs(i, j, root->child[idx], temp);
					visited[i][j] = false;
				}
			}
		}

		int total = 0;
		string max_word = "";

		for (const string& word : founded) {
			total += score_board[word.size()];

			if (word.size() > max_word.size()) 
			{
				max_word = word;
			}
			else if (word.size() == max_word.size() && word < max_word)
			{
				max_word = word;
			}
		}

		cout << total << " " << max_word << " " << founded.size() << "\n";
	}

	delete root;

	return 0;
}