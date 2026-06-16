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
    bool fun(TreeNode* root, long long mi, long long mx) {
        if (root == nullptr) return true;
        if (root->val <= mi || root->val >= mx) return false;

        return fun(root->left, mi, root->val) && fun(root->right, root->val, mx);
    }
    bool isValidBST(TreeNode* root) {
        return fun(root, LONG_MIN, LONG_MAX);
    }
};