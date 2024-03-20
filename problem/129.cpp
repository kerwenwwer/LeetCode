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
    int ans = 0;
    int sumNumbers(TreeNode *root)
    {
        traverse(root, 0);
        return ans;
    }

private:
    int traverse(TreeNode *t, int num)
    {
        if (!t)
            return num;
        num = num * 10 + t->val;
        if (t->left || t->right)
        {
            // not leaft traverse
            traverse(t->left, num);
            traverse(t->right, num);
        }
        else
        {
            ans += num; // In the leaf -> add one path to ans;
        }
        return ans;
    }
};