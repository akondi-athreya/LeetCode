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
    int cnt = 0;
    pair<int, int> fun(TreeNode* root) {
        if (root == NULL) return {0, 0};

        pair<int, int> l = fun(root->left);
        pair<int, int> r = fun(root->right);

        int su = l.first + r.first + root->val;
        int ncnt = l.second + r.second + 1;

        if (root->val == su/ncnt) cnt++;

        return {su, ncnt};
    }
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return cnt;
    }
};