#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int n;
vector<int> inorder, postorder;
unordered_map<int, int> inorder_idx;

void find(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
	{
		return;
	}

	int root = postorder[postEnd];
	cout << root << " ";

	int rootIndex = inorder_idx[root];
	int size = rootIndex - inStart;

	find(inStart, rootIndex - 1, postStart, postStart + size - 1);
	find(rootIndex + 1, inEnd, postStart + size, postEnd - 1);
}

int main()
{
	cin >> n;

	inorder = postorder = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
		inorder_idx[inorder[i]] = i;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> postorder[i];
	}

	find(0, n - 1, 0, n - 1);

	return 0;
}