class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int su = 0;
        int arrsum = 0;
        for (int i = 0 ; i < n ; i++) {
            su += nums[i]*i;
            arrsum += nums[i];
        }
        dp[0] = su;
        for (int i = 1 ; i < n ; i++) {
            dp[i] = dp[i-1] + arrsum - (n*nums[n-i]);
        }
        int ans = INT_MIN;
        for(int num : dp) ans = max(ans, num);
        return ans;
    }
};