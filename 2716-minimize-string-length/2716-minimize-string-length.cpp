class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> v(26, 0);
        for (char ch : s) v[ch-'a']++;
        int cnt = 0;
        for (int i : v) {
            if (i > 0) cnt++;
        }
        return cnt;
    }
};