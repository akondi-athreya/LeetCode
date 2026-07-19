class Solution {
public:
    string decodeMessage(string key, string message) {
        int i = 0;
        unordered_map<char, int> mp;
        for (char c : key) {
            if (c != ' ' && mp.find(c) == mp.end()) {
                mp[c] = 'a'+i;
                i++;
            }
        }
        string ans = "";
        for (char ch : message) {
            if (ch != ' ') ans += mp[ch];
            else ans += ' ';
        }
        return ans;
    }
};