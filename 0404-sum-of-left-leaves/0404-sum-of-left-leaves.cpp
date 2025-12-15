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
class Solution {
public:
    void fun(TreeNode* node, int& ans) {
        if (!node) return;
        fun(node->left, ans);

        if (node->left) {
            if (!node->left->left && !node->left->right) {
                ans += node->left->val;
            }
        }
        fun(node->right, ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        fun(root, ans);
        return ans;
    }
};