class Solution {
public:
    bool fun(vector<string>& strs, int i) {
        for (int j = 1 ; j < strs.size() ; j++) {
            if (strs[j][i] < strs[j - 1][i]) return true;
        }
        return false;
    }
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int i = 0 ; i < strs[0].size() ; i++) {
            ans += fun(strs, i);
        }
        return ans;
    }
};