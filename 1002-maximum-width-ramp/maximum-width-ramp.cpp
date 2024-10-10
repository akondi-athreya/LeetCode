class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rrr(n);

        rrr[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rrr[i] = max(rrr[i + 1], nums[i]);
        }

        int left = 0, right = 0;
        int mmx = 0;


        while (right < n) {
            while (left < right && nums[left] > rrr[right]) {
                left++;
            }
            mmx = max(mmx, right - left);
            right++;
        }

        return mmx;
    }
};