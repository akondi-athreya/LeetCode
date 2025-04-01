class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dis = INT_MAX;
        int ans;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(abs(nums[i] - 0) == dis) {
                ans = max(nums[i], ans);
            }
            if(abs(nums[i] - 0) < dis) {
                ans = nums[i];
                dis = abs(nums[i] - 0);
            }
        }

        return ans;
    }
};