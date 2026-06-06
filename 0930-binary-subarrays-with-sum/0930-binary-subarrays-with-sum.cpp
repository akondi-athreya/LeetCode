class Solution {
public:
    int fun(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int su = 0;
        int l = 0, r = 0, n = nums.size();

        int cnt = 0;
        while (r < n) {
            su += nums[r];

            while (su > goal) {
                su -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums, goal) - fun(nums, goal-1);
    }
};