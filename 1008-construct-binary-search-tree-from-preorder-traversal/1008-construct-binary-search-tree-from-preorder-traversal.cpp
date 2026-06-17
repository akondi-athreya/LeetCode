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
    TreeNode* fun(vector<int>&v, int& i, int bound) {
        if (i == v.size() || v[i] > bound) return NULL;
        TreeNode* root = new TreeNode(v[i]);
        i++;
        root->left = fun(v, i, root->val);
        root->right = fun(v, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return fun(preorder, i, INT_MAX);
    }
};