class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int su = 0;
        string ans = "";

        for (string s : words) {
            su = 0;
            for (int i = 0 ; i < s.size() ; i++) {
                su += weights[s[i]-'a'];
            }
            su %= 26;
            ans.push_back((char)('z'-su));
        }
        return ans;
    }
};