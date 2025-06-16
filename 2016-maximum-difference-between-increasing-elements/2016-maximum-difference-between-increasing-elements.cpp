class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for(int i = 0 ; i < n-1 ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                if(nums[j] > nums[i]) {
                    ans = max(ans, nums[j] - nums[i]);
                }
            }
        }
        return ans;
    }
};