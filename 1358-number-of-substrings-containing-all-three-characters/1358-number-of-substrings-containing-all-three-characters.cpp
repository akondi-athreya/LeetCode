class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mp(3, 0);
        int l = 0, r = 0;
        int res = 0;

        int n = s.size();

        while (r < n) {
            mp[s[r] - 'a']++;
            while ((mp[0] > 0) && (mp[1] > 0) && (mp[2] > 0)) {
                res += (n - r);
                mp[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return res;
    }
};