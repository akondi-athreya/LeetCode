class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
                mx = max(mx, (int)st.size());
            }
            else if (ch == ')') {
                st.pop();
            }
        }
        return mx;
    }
};