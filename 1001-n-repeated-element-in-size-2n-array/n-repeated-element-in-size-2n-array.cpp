class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            if (mp.count(i)) return i;
            mp[i]++;
        }
        return nums.size();
    }
};