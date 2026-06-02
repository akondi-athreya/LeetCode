class Solution {
public:
    vector<int> generateNSE(vector<int>&nums, int n) {
        stack<int> st;
        vector<int> ans(n);

        for (int i = n-1 ; i >= 0 ; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = (!st.empty()) ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> generatePSE(vector<int>&nums, int n) {
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0 ; i < n ; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            ans[i] = (!st.empty()) ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    vector<int> generateNGE(vector<int>&nums, int n) {
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1 ; i >= 0 ; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            ans[i] = (!st.empty()) ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> generatePGE(vector<int>&nums, int n) {
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0 ; i < n ; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            ans[i] = (!st.empty()) ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    long long subarrayMins(vector<int>&arr, int n) {
        vector<int> nse = generateNSE(arr, n);
        vector<int> pse = generatePSE(arr, n);

        long long su = 0;

        for (int i = 0 ; i < n ; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = left*right*1LL;
            long long val = (freq*arr[i]*1LL);
            su += val;
        }
        return su;
    }
    long long subarrayMaxs(vector<int>&arr, int n) {
        vector<int> nge = generateNGE(arr, n);
        vector<int> pge = generatePGE(arr, n);

        long long su = 0;

        for (int i = 0 ; i < n ; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;
            long long freq = left*right*1LL;
            long long val = (freq*arr[i]*1LL);
            su += val;
        }
        return su;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        return (subarrayMaxs(nums, n) - subarrayMins(nums, n));
    }
};