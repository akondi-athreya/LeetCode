class Solution {
public:
    string fun(string s) {
        reverse(begin(s), end(s));
        return s;
    }
    string finalString(string s) {
        string ans = "";
        for (char ch : s) {
            if (ch == 'i') {
                ans = fun(ans);
            }
            else ans += ch;
        }
        return ans;
    }
};