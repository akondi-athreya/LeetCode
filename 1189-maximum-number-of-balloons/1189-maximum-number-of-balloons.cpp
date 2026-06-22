class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for (char& ch: text) {
            mp[ch]++;
        }
        int ans = INT_MAX;
        string s = "balloon";
        for (char& ch : s) {
            if (ch == 'l' || ch == 'o') {
                ans = min(ans, mp[ch]/2);
            }
            else ans = min(ans, mp[ch]);
        }
        return ans;
    }
};