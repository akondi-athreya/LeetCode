typedef long long ll;
#define all(x) begin(x),end(x)
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(all(nums));
        ll sum = 0, res = -1;
        for (int i : nums) {
            if (sum > i) {
                res = max(res, sum + i);
            }
            sum += i;
        }
        return res;
    }
};