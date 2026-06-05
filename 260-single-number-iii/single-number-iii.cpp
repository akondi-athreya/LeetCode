class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long x = 0;

        for (int i = 0 ; i < n ; i++) {
            x = x ^ nums[i];
        }

        int r = (x & (x-1)) ^ x;

        int a = 0, b = 0;

        for (int i = 0 ; i < n ; i++) {
            if (nums[i] & r) a = a ^ nums[i];
            else b = b ^ nums[i];
        }

        if (a < b) return {a, b};
        return {b, a};
    }
};