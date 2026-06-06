class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();

        vector<int> mp(26, 0);

        int res = 0, ans = 0;

        while (r < n) {
            mp[s[r] - 'A']++;
            res = max(res, mp[s[r] - 'A']);
            if ((r-l+1)-res > k) {
                mp[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};