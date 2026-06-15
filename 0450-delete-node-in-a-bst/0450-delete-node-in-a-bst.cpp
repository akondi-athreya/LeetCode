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
    TreeNode* fun(TreeNode* root) {
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;

        TreeNode* RC = root->right;
        TreeNode* LR = lastRight(root->left);
        LR->right = RC;
        return root->left;
    }
    TreeNode* lastRight(TreeNode* root) {
        if (root->right == NULL) return root;
        return lastRight(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) return fun(root);
        TreeNode* dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = fun(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = fun(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};