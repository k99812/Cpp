#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left, *right;

     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution 
{
    unordered_map<TreeNode*, int> dp;

    int dfs(TreeNode* node)
    {
        if (node == nullptr) return 0;

        if (dp.find(node) != dp.end()) return dp[node];

        int val = node->val;
        if (node->left)
        {
            val += dfs(node->left->left) + dfs(node->left->right);
        }
        if (node->right)
        {
            val += dfs(node->right->left) + dfs(node->right->right);
        }

        return dp[node] = max(val, dfs(node->left) + dfs(node->right));
    }

public:
    int rob(TreeNode* root) 
    {
        return dfs(root);
    }
};

int main()
{

	return 0;
}