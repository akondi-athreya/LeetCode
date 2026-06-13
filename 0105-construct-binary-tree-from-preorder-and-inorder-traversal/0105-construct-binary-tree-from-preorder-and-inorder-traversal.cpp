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
        vector<int>&preorder, int p_start, int p_end,
        vector<int>&inorder, int i_start, int i_end,
        map<int, int>&mp
    ) {
        if (p_start > p_end || i_start > i_end) return nullptr;

        TreeNode* root = new TreeNode(preorder[p_start]);

        int i_root = mp[root->val];
        int num_left = i_root - i_start;

        root->left = fun(
            preorder, p_start + 1, p_start + num_left,
            inorder, i_start, i_root-1,
            mp
        );

        root->right = fun(
            preorder, p_start + num_left + 1, p_end,
            inorder, i_root + 1, i_end,
            mp
        );

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;

        for (int i = 0 ; i < inorder.size() ; i++) {
            mp[inorder[i]] = i;
        }

        return fun(
            preorder, 0, preorder.size()-1,
            inorder, 0, inorder.size()-1,
            mp
        );
    }
};