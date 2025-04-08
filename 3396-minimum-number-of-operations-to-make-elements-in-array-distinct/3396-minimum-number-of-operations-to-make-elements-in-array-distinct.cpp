class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0, cpy;
        while (true) {
            unordered_map<int, int> mp;
            cpy = 0;
            for (int num : nums)
                if (++mp[num] == 2) cpy++;

            if (cpy == 0) break;
            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            ans++;
        }
        return ans;
    }
};