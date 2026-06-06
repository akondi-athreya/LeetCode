class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        vector<int> ans(n);
        int left_sum = 0;

        for (int i = 0 ; i < n ; i++) {
            int right_sum = total_sum - left_sum - nums[i];
            ans[i] = abs(left_sum - right_sum);
            left_sum += nums[i];
        }

        return ans;
    }
};