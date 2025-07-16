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
    int fun(TreeNode* root) {
        if (root == NULL) return 0;

        int lH = fun(root->left);

        if (lH == -1) return -1;

        int rH = fun(root->right);

        if (rH == -1) return -1;

        if (abs(lH - rH) > 1) return -1;

        return max(lH, rH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return fun(root) != -1;
    }
};