class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int cnt = 0, n = nums.size(), a = k;
        while (cnt < n) {
            if (!mp.count(a)) {
                return a;
            }
            a += k;
            cnt++;
        }
        return a;
    }
};