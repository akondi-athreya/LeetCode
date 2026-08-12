class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans = "";
        int n = s.size();
        for (char ch : s) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ans += ch;
        }

        for (int i = 0 ; i < n ; i++) {
            char ch = s[i];
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                s[i] = ans.back();
                ans.pop_back();
            }
        }
        return s;
    }
};