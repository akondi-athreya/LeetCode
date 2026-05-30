class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 2*n - 1 ; i >= 0 ; i--) {
            int idx = i % n;
            int curr = nums[idx];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (i < n) {
                if (st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
            st.push(curr);
        }
        return ans;
    }
};