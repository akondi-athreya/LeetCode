class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, minLength = INT_MAX;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= target) {
                minLength = min(minLength, j - i + 1);
                sum -= nums[i++];
            }
            ++j;
        }
        return (minLength != INT_MAX) ? minLength : 0;
    }
};