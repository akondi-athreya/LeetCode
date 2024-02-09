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
    void LevelOrderTraversal(TreeNode *root , vector<vector<int>>&res){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            while(size--){
                TreeNode* p = q.front();
                q.pop();
                v.emplace_back(p->val);
                if(p->left != NULL) q.push(p->left);
                if(p->right != NULL) q.push(p->right);
            }
            res.emplace_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        LevelOrderTraversal(root , res);
        return res;
    }
};