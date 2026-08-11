class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> v(26, 0);
        for (char ch : s) {
            v[ch - 'a']++;
        }
        int cnt = v[s[0] - 'a'];
        for (char ch : s) {
            if (v[ch - 'a'] != cnt) return false;
        }
        return true;
    }
};