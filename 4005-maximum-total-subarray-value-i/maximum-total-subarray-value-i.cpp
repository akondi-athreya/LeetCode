class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mi = *min_element(begin(nums), end(nums));
        long long mx = *max_element(begin(nums), end(nums));

        long long ans = mx - mi;


        return (1LL * k) * ans;
    }
};