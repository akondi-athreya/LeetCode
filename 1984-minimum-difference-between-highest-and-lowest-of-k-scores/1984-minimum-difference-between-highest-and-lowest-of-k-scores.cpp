class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int i = 0;
        int j = i+k-1;
        int n = nums.size();
        if (k >= n) return nums[n-1] - nums[0];
        if (k==1 || n==1) return 0;
        
        int ans = INT_MAX;

        while (j < n) {
            ans = min(ans, nums[j]-nums[i]);
            i++;
            j++;
        }

        return ans;

    }
};