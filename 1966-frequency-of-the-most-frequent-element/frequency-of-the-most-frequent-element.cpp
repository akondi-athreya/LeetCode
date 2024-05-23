class Solution {
public:
    bool can(vector<int>& nums, int len, int k) {
        long long sum = 0;
        for (int i = 0; i < len-1; i++){
            sum += nums[i];
        }
        for (int i = 0, j = len - 1; j < nums.size(); j++, i++) {
            sum += nums[j];
            long long need = 1LL * nums[j] * len;
            if (need - sum <= k) {
                return true;
            }
            sum =sum - nums[i];
        }
        return false;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int low = 1;
        int high = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can(nums, mid, k)){
                ans = mid;
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};