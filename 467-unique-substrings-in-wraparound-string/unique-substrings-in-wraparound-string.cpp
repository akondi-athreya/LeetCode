class Solution {
public:
    int findSubstringInWraproundString(string s) {
        if (s.empty()) return 0;

        int n = s.size();

        vector<int> v(26, 0);
        int cnt = 1;
        v[s[0] - 'a'] = 1;

        for (int i = 1 ; i < n ; i++) {
            if ((s[i] - s[i-1] == 1) || (s[i-1] == 'z' && s[i] == 'a')) cnt++;
            else cnt = 1;
            v[s[i] - 'a'] = max(v[s[i] - 'a'], cnt);
        }
        int ans = 0;
        for (int i : v) {
            ans += i;
        }
        return ans;
    }
};