class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count_mp;
        int p = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int get = count_mp[nums[i]];
            if (get == k) {
                while (nums[p] != nums[i]) {
                    int curr = nums[p++];
                    int c = count_mp[curr];
                    if (c == 1) count_mp.erase(curr);
                    else count_mp[curr] = c - 1;
                }
                p++;
                get--;
            }
            count_mp[nums[i]] = get + 1;
            ans = max(ans, i - p + 1);
        }
        return ans;
    }
};