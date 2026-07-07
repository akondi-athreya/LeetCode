class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        string s = to_string(n);
        string nn = "";
        for (char& ch : s) {
            if (ch != '0') nn += ch;
        }
        long long ss = 0;
        for (char& ch : nn) {
            ss += (ch - '0');
        }
        return stoi(nn)*ss;
    }
};