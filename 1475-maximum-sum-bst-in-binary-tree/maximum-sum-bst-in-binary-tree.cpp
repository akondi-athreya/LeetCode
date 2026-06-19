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

class Node {
public:
    int maxNode, minNode, sum;
    bool isBST;
    Node(int minNode, int maxNode, int sum, bool isBST) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->isBST = isBST;
    }
};
class Solution {
public:
    int ans = 0;
    Node fun(TreeNode* root) {
        if (!root) return Node(INT_MAX, INT_MIN, 0, true);

        auto left = fun(root->left);
        auto right = fun(root->right);

        if (left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode) {
            int curr = left.sum + right.sum + root->val;
            ans = max(ans, curr);
            return Node(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                curr,
                true
            );
        }

        return Node(INT_MIN, INT_MAX, 0, false);
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        fun(root);
        return ans;
    }
};