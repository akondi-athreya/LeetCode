class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();

        int currsum = 0;
        mp[0] = 1;

        long long su = 0;
        long long res = 0;

        for (int i = 0 ; i < n ; i++) {
            if (nums[i] == target) {
                su += mp[currsum];
                currsum++;
            }
            else {
                currsum--;
                su -= mp[currsum];
            }
            mp[currsum]++;
            res += su;
        }
        
        return res;
    }
};