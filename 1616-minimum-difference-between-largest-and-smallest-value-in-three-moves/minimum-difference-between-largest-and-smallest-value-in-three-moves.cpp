class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int res = INT_MAX;
        res = min(res , nums[n-4] - nums[0]);
        res = min(res , nums[n-1] - nums[3]);
        res = min(res , nums[n-3] - nums[1]);
        res = min(res , nums[n-2] - nums[2]);
        return res;
    }
};