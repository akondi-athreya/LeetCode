typedef long long ll;
class Solution {
public:
    ll fun(vector<int>& nums, ll mid) {
        ll su = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            su += (nums[i] + mid - 1) / mid;
        }
        return su;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        ll low = 1, high = *max_element(begin(nums), end(nums));
        ll ans = INT_MAX;
        while(low <= high) {
            ll mid = (low + high) >> 1;
            ll su = fun(nums, mid);
            if(su > threshold) low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};