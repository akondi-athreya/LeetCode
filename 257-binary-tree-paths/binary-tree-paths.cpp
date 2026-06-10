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
    bool fun(TreeNode* root, vector<string>&ans, string s) {
        s += to_string(root->val);
        if (root->left != NULL || root->right != NULL) {
            s += "->";
        }
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(s);
            return true;
        }
        if (root->left) {
            fun(root->left, ans, s);
        }
        if (root->right) {
            fun(root->right, ans, s);
        }
        return true;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;

        string s = "";

        fun(root, ans, s);

        return ans;
    }
};