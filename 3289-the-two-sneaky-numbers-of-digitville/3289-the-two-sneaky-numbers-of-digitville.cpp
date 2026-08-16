class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> v;
        for (int num : nums) {
            v[num]++;
        }
        vector<int> ans(2, -1);
        for (auto it : v) {
            if (it.second == 2) {
                if (ans[0] == -1) ans[0] = it.first;
                else ans[1] = it.first;
            }
        }
        return ans;
    }
};