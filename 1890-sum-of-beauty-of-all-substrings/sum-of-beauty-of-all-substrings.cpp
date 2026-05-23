class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0 ; i < n ; i++) {
            // unordered_map<char, int> mp;
            int mp[26] = {0};
            for (int j = i ; j < n ; j++) {
                mp[s[j] - 'a']++;

                int mi = INT_MAX;
                int mx = INT_MIN;
                for (int k = 0 ; k < 26 ; k++) {
                    if (mp[k] != 0) {
                        mi = min(mi, mp[k]);
                        mx = max(mx, mp[k]);
                    }
                }
                res += (mx - mi);
            }
        }
        return res;
    }
};