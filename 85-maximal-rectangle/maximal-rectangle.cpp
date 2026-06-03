class Solution {
public:
    int fun(vector<int>&v, int m) {
        stack<int> st;
        v.push_back(0);
        int res = 0;

        for (int i = 0 ; i < m+1 ; i++) {
            while (!st.empty() && v[i] < v[st.top()]) {
                int a = v[st.top()];
                st.pop();
                int b = (st.empty()) ? i : i - st.top() - 1;
                res = max(res, a*b);
            }
            st.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (matrix.empty()) return 0;

        vector<int> height(m, 0);

        int ans = 0;

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            ans = max(ans, fun(height, m));
        }
        return ans;
    }
};