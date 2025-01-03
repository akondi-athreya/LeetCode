class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long lsum = 0, rsum = 0;
        for (int num : nums) {
            rsum += num;
        }

        int cnt = 0;
        for (int i=0 ; i<nums.size()-1 ; i++) {
            lsum += nums[i];
            rsum -= nums[i];

            if (lsum >= rsum) {
                cnt++;
            }
        }

        return cnt;
    }
};