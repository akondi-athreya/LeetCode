class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pre = 0, cnt = 0;
        mp[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++) {
            pre += nums[i];
            int x = pre - k;
            cnt += mp[x];
            mp[pre] += 1;
        }
        return cnt;
    }
};