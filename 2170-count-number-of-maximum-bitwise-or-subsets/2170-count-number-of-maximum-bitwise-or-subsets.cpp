class Solution {
public:
    int fun(int idx, int ans, vector<int>&nums, int maxOr) {
        if(idx == nums.size()) {
            if(ans == maxOr) return 1;

            return 0;
        }

        int plus = fun(idx+1, ans|nums[idx], nums, maxOr);

        int minus = fun(idx+1, ans, nums, maxOr);

        return plus + minus;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int num : nums) maxOr |= num;

        int ans = 0;
        return fun(0, ans, nums, maxOr);
    }
};