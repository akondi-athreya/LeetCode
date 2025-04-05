class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (int i : nums) {
            res |= i;
        }
        return res << (nums.size() - 1);
    }
};