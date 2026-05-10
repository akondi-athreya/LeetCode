class Solution {
public:
    int fun(vector<int>& nums, int mid) {
        int sub_sum = 0, cnt = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (sub_sum + nums[i] <= mid) {
                sub_sum += nums[i];
            }
            else {
                cnt++;
                sub_sum = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int mx = *max_element(begin(nums), end(nums));
        int su = accumulate(begin(nums), end(nums), 0);

        int low = mx, high = su;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = fun(nums, mid);
            // cout << mid << " - " << cnt << endl;
            if (cnt < k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};