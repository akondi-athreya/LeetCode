class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a = 0, b = 0, c = 0;
        int mi = INT_MAX, mx = INT_MIN;
        int mi_idx = -1, mx_idx = -1;
        for (int i = 0 ; i < nums.size() ; i++) {
            int n = nums[i];
            if (n < mi)  {
                mi = n;
                mi_idx = i;
            }
            if (n > mx) {
                mx = n;
                mx_idx = i;
            }
        }
        int n = nums.size();
        int ff = min(mi_idx, mx_idx);
        int ll = max(mi_idx, mx_idx);
        a = ll + 1;
        b = n - ff;
        c = (ff+1) + (n-ll);
        return min({a, b, c});
    }
};