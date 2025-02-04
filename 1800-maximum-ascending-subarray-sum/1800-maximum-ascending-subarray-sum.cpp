class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> PrefixSum(n, 0);
        if(n == 1) return nums[0];
        PrefixSum[0] = nums[0];
        for (int i = 1 ; i < n ; i++) {
            PrefixSum[i] = PrefixSum[i-1] + nums[i];
        }
        int mx = INT_MIN;
        int sum = 0;
        for (int i = 0 ; i < n-1 ; i++) {
            sum += nums[i];
            if(nums[i] >= nums[i+1]) {
                mx = max(mx, sum);
                sum = 0;
            }
        }
        if(nums[n-2] != nums[n-1]) sum += nums[n-1];
        mx = max(mx, sum);
        return mx;
    }
};