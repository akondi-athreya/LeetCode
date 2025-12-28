class Solution {
public:
    bool fun(int n, int k) {
        int cnt = 0;
        while (n > 0) {
            if (n & 1) cnt++;
            n = n >> 1;
        }
        return cnt==k;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++) {
            if (fun(i, k)) ans += nums[i];
        }
        return ans;
    }
};