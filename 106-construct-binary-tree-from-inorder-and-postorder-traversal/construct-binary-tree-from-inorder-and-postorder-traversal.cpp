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
    TreeNode* fun(
        vector<int>&inorder, int i_start, int i_end,
        vector<int>&preorder, int p_start, int p_end,
        map<int, int>&mp
    ) {
        if (p_start > p_end || i_start > i_end) return nullptr;

        TreeNode* root = new TreeNode(preorder[p_end]);

        int i_root = mp[root->val];
        int num_left = i_root - i_start;

        root->left = fun(
            inorder, i_start, i_root-1,
            preorder, p_start, p_start + num_left - 1,
            mp
        );

        root->right = fun(
            inorder, i_root + 1, i_end,
            preorder, p_start + num_left, p_end - 1,
            mp
        );

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return nullptr;

        map<int, int> mp;
        for (int i = 0 ; i < inorder.size() ; i++) {
            mp[inorder[i]] = i;
        }

        return fun(
            inorder, 0, inorder.size()-1,
            postorder, 0, postorder.size()-1,
            mp
        );
    }
};