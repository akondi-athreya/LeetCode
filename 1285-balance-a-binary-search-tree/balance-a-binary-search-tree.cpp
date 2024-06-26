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
private:
    void rightR(TreeNode* p , TreeNode* n){
        TreeNode* cpy = n->left;
        n->left = cpy->right;
        cpy->right = n;
        p->right = cpy;
    }
    void leftR(TreeNode* p , TreeNode* n){
        TreeNode* cpy = n->right;
        n->right = cpy->left;
        cpy->left = n;
        p->right = cpy;
    }
    void makeR(TreeNode* head , int cnt){
        TreeNode* cur = head;
        for(int i=0 ; i<cnt ; i++){
            TreeNode* cpy = cur->right;
            leftR(cur , cpy);
            cur = cur->right;
        }
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* head = new TreeNode(0);
        head->right = root;
        TreeNode* cur = head;
        while(cur->right){
            if(cur->right->left) rightR(cur , cur->right);
            else cur = cur->right;
        }
        int ncnt = 0;
        cur = head->right;
        while(cur){
            ++ncnt;
            cur = cur->right;
        }
        int m = pow(2 , floor(log2(ncnt+1))) -1;
        makeR(head , ncnt-m);
        while(m>1){
            m/=2;
            makeR(head , m);
        }
        TreeNode* b = head->right;
        delete head;
        return b;
    }
};