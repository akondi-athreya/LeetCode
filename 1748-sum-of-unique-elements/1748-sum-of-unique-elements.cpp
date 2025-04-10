class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto it : mp) {
            if(it.second == 1) {
                ans += it.first;
            }
        }
        return ans;
    }
};