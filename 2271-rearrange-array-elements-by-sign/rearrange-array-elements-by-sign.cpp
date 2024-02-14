class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int v: nums) {
            if (v > 0) {
                pos.push_back(v);
            } else if (v < 0) {
                neg.push_back(v);
            }
        }
        const int n = nums.size() / 2;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};