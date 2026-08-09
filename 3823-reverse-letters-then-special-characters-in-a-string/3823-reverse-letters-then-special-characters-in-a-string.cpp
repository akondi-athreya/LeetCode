class Solution {
public:
    string reverseByType(string s) {
        string a = "", b = "";
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') a += ch;
            else b += ch;
        }
        // reverse(begin(a), end(a));
        // reverse(begin(b), end(b));
        string ans = "";
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                ans += a.back();
                a.pop_back();
            }
            else {
                ans += b.back();
                b.pop_back();
            }
        }
        return ans;
    }
};