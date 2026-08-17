class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> b;
        for (int i = 0 ; i < n ; i++) {
            b.push_back(make_pair(nums[i], i));
        }
        sort(begin(b), end(b));
        vector<int> ans(n);
        for (int i = 0 ; i < n ; i++) {
            if (i > 0 && b[i].first == b[i-1].first) {
                ans[b[i].second] = ans[b[i-1].second];
            } else {
                ans[b[i].second] = i;
            }
        }
        return ans;
    }
};