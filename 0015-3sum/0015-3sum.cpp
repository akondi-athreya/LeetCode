class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                int su = nums[i] + nums[j] + nums[k];
                if (su == 0) {
                    ans.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                }
                else if (su > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return ans;
    }
};