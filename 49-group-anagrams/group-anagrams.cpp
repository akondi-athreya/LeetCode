class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> vals;
        for (auto str: strs) {
            vector<int> freqs(26, 0);
            string s = "";
            for (auto c: str) {
                freqs[c - 'a'] += 1;
            }
            for (auto freq: freqs) {
                s += to_string(freq) + "_";
            }
            // cout << s << endl;
            vals[s].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto p: vals) {
            ans.push_back(p.second);
        }
        return ans;
    }
};