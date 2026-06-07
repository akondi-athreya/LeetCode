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
    void fun(TreeNode* root, int target, vector<int>&v, vector<vector<int>>&res) {
        if (root == nullptr) {
            return;
        }

        v.push_back(root->val);
        target -= root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (target == 0) {
                res.push_back(v);
            }
        }
        else {
            fun(root->left, target, v, res);
            fun(root->right, target, v, res);
        }
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        fun(root, targetSum, v, res);
        return res;
    }
};