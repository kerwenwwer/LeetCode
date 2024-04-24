/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        DFS(root, 0, ans);
        return ans;
    }

private:
    void DFS(TreeNode *root, int depth, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        while (ans.size() <= depth)
            ans.push_back({});
        ans[depth].push_back(root->val);
        DFS(root->left, depth + 1, ans);
        DFS(root->right, depth + 1, ans);
    }
};