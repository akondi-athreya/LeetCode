class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(begin(arr), end(arr));

        int ans = -1;

        for (int i = 0 ; i < n ; i++) {
            if (i == 0) {
                arr[i] = 1;
            }
            else if (abs(arr[i] - arr[i-1]) > 1){
                arr[i] = arr[i-1] + 1;
            }
            ans = max(ans, arr[i]);
        }

        return ans;
    }
};