class Solution {
public:
    int maxDistinct(string s) {
        int mp[26] = {0};
        int ans = 0;
        for (char& ch : s) {
            if (mp[ch-'a'] == 0) {
                ans++;
                mp[ch-'a'] = 1;
            }
        }
        return ans;
    }
};