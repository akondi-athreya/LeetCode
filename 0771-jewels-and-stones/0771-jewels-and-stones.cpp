class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int mp1[26] = {0};
        int mp2[26] = {0};
        for (char& ch : jewels) {
            if (ch >= 'a' && ch <= 'z') {
                mp1[ch-'a']++;
            }
            else {
                mp2[ch-'A']++;
            }
        }
        int ans = 0;
        for (char& ch : stones) {
            if (ch >= 'a' && ch <= 'z') {
                if (mp1[ch-'a'] > 0) ans++;
            }
            else {
                if (mp2[ch-'A'] > 0) ans++;
            }
        }
        return ans;
    }
};