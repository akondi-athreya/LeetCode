class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int fs = 0 , ls = 0;
        for (int i = 0 ; i < k ; i++) {
            fs += nums[i];
            ls += nums[n-i-1];
        }
        return abs(fs - ls);
    }
};