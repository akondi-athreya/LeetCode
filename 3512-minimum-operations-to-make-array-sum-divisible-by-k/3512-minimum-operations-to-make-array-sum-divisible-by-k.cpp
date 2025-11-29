class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int su = 0;
        for (int num : nums) su += num;
        if (su < k) return su;
        if (su == k) return 0;

        return su % k;
    }
};