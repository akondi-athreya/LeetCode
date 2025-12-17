class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;
        st.push(s[0]);

        for (int i = 1 ; i < n ; i++) {
            // cout << s[i] << st.top() << "\n";
            char ch = s[i];
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            char tp = st.top();
            if (!(ch == tp) && (tolower(ch) == tp || tolower(tp) == ch)) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};