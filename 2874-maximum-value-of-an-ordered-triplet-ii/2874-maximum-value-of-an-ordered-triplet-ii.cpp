class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftarr(n), rightarr(n);

        for (int i = 1; i < n; i++) {
            leftarr[i] = max(leftarr[i - 1], nums[i - 1]);
            rightarr[n - 1 - i] = max(rightarr[n - i], nums[n - i]);
        }

        long long ans = 0;

        for (int j = 1; j < n - 1; j++) {
            ans = max(ans, (long long)(leftarr[j] - nums[j]) * rightarr[j]);
        }
        
        return ans;
    }
};