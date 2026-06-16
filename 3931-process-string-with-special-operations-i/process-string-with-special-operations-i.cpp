class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') ans += ch;
            else if (ch == '#') {
                ans += ans;
            }
            else if (ch == '%') {
                if (!ans.empty()) reverse(ans.begin(), ans.end());
            }
            else if (ch == '*') {
                if (!ans.empty()) ans.pop_back();
            }
        }
        return ans;
    }
};