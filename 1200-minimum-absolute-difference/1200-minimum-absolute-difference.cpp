class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        int mi = INT_MAX;
        for (int i = 1 ; i < n ; i++) {
            mi = min(mi, arr[i]-arr[i-1]);
        }
        for (int i = 0 ; i < n-1 ; i++) {
            if (arr[i+1] - arr[i] == mi) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};