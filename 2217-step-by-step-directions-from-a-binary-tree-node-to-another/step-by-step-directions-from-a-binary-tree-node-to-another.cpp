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
    bool fun(TreeNode* root , int target , string&path){
        if(root == NULL) return false;
        if(root->val == target) return true;
        path.push_back('L');
        if(fun(root->left , target , path) == true) return true;
        path.pop_back();

        path.push_back('R');
        if(fun(root->right , target , path) == true) return true;
        path.pop_back();
        return  false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rTOs = "";
        string rTOd = "";
        fun(root , startValue , rTOs);
        fun(root , destValue , rTOd);

        int k=0;
        while(k<rTOs.size() && k<rTOd.size() && rTOs[k]==rTOd[k]) k++;

        string ans="";
        for(int i=0 ; i<rTOs.size()-k ; i++) ans+='U';
        for(int i=k ; i<rTOd.size() ; i++) ans+=rTOd[i];
        return ans;
    }
};