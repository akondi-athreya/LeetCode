class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        for (int i = 0 ; i < n ; i++) {
            char ch = num[i];

            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        if (st.empty()) return "0";

        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        while (res.size() > 0 && res.back() == '0') res.pop_back();

        reverse(begin(res), end(res));
        
        if (res.empty()) return "0";

        return res;
    }
};