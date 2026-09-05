class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n);
        vector<int> s(n);
        int val = nums[0];
        for (int i = 0 ; i < n ; i++) {
            val = max(val, nums[i]);
            f[i] = val;
        }
        val = nums[n-1];
        for (int i = n-1 ; i >= 0 ; i--) {
            val = min(val, nums[i]);
            s[i] = val;
        }
        for (int i = 0 ; i < n ; i++) {
            int res = f[i] - s[i];
            if (res <= k) return i;
        }
        return -1;
    }
};