class Solution {
public:
    bool fun(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int i = 1;
        while (i < n-1) {
            if ((arr[i] - arr[i-1]) != (arr[i+1] - arr[i])) {
                return false;
            }
            i++;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int m = l.size();
        for (int i = 0 ; i < m ; i++) {
            vector<int> arr(nums.begin()+l[i], nums.begin()+r[i]+1);
            ans.push_back(fun(arr));
        }
        return ans;
    }
};