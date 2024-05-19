/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* find(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original != NULL){
            if(original->val == target->val) return cloned;
            TreeNode* leftResult = find(original->left , cloned->left , target);
            if(leftResult != NULL) return leftResult;
            TreeNode* rightResult = find(original->right , cloned->right , target);
            if(rightResult != NULL) return rightResult;
        }
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = find(original , cloned , target);
        return ans;
    }
};