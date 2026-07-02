class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;
        string s = to_string(n);
        int sz = s.size();
        int f = sz;
        for (int i = sz-1 ; i > 0 ; i--) {
            if (s[i-1] > s[i]) {
                f = i;
                s[i-1]--;
            }
        }
        for (int i = f ; i < sz ; i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};