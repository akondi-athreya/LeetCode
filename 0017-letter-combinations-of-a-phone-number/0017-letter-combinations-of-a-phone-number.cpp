class Solution {
public:
    vector<string> res;
    void fun(string& n, int idx, string& curr, vector<string>&v) {
        if(idx == n.length()) {
            res.emplace_back(curr);
            return;
        }
        string ltrs = v[n[idx] - '0'];
        for(auto l : ltrs) {
            curr.push_back(l);
            fun(n, idx+1, curr, v);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr = "";
        fun(digits, 0, curr, v);
        return res;
    }
};