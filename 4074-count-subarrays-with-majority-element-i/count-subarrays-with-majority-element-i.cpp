class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        int res = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = i ; j < n ; j++) {
                if (nums[j] == target) cnt++;
                if (cnt > ((j-i+1) / 2)) res++;
            }
            cnt = 0;
        }
        
        return res;
    }
};