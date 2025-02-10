class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        int n = s.size();
        while (i < n) {
            if (isdigit(s[i])) {
                s.erase(i, 1);
                if (i > 0) {
                    s.erase(i - 1, 1);
                    i--;
                }
            }
            else i++;
        }
        return s;
    }
};