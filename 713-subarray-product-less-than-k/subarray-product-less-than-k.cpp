class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        int i = 0, j = 0, pro = 1;
        while (j < n) {
            pro *= nums[j];
            while (i <= j && pro >= k) {
                pro /= nums[i];
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
};
