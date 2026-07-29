class Solution {
public:
    int countAsterisks(string s) {
        bool toCount = true;
        int ans = 0;
        for (char ch : s) {
            if (ch == '|') {
                toCount = !toCount;
                continue;
            }
            if (ch == '*') {
                if (toCount) ans++;
            }
        }
        return ans;
    }
};