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
    void print(TreeNode* temp , vector<int>&v){
        if(temp!=NULL){
            print(temp->left,v);
            v.emplace_back(temp->val);
            print(temp->right,v);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        print(root,v);
        return v;
    }
};