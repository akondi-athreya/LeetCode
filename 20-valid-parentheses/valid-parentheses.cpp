class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if (st.empty()) return false;
                char tt = st.top();
                st.pop();
                if ((ch == ')' && tt != '(') ||
                    (ch == '}' && tt != '{') ||
                    (ch == ']' && tt != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};