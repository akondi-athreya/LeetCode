class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, ans = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == 0) cnt++;
            else cnt = 0;

            ans = ans + cnt;
        }
        return ans;
    }
};