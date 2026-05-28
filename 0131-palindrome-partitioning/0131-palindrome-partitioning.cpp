class Solution {
public:
    void fun (vector<vector<string>>&res, vector<string>&path, int idx, string s) {
        if (idx == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = idx ; i < s.size() ; i++) {
            if (isPalin(s, idx, i)) {
                path.push_back(s.substr(idx, i-idx+1));
                fun(res, path, i+1, s);
                path.pop_back();
            }
        }
    }
    bool isPalin (string s, int l, int h) {
        while (l <= h) {
            if (s[l++] != s[h--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        fun(res, path, 0, s);
        return res;
    }
};