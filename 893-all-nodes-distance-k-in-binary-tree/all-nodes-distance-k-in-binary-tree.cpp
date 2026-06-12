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
    void bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        unordered_map<TreeNode*, TreeNode*> mp;
        bfs(root, mp);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> st;

        q.push(target);
        st.insert(target);

        int cnt = 0;

        while (!q.empty()) {
            int n = q.size();

            if (cnt++ == k) break;

            for (int i = 0 ; i < n ; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !st.count(curr->left)) {
                    q.push(curr->left);
                    st.insert(curr->left);
                }
                if (curr->right && !st.count(curr->right)) {
                    q.push(curr->right);
                    st.insert(curr->right);
                }

                if (mp.count(curr) && !st.count(mp[curr])) {
                    q.push(mp[curr]);
                    st.insert(mp[curr]);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};