class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0 ; i < n; i++) {
            for (int j = i + 1 ; j < n ; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        for (auto [i, j] : mp) {
            int ans = (j - 1) * j / 2;
            res += 8 * ans;
        }
        return res;
    }
};