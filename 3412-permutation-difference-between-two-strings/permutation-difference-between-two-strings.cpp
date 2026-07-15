class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<int, int> mp;
        int n = s.size();
        for (int i = 0 ; i < n ; i++) {
            mp[s[i]] = i;
        }
        int ans = 0;
        n = t.size();
        for (int i = 0 ; i < n ; i++) {
            ans += abs(mp[t[i]] - i);
        }
        return ans;
    }
};