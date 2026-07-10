class Solution {
public:
    void fun(int n, vector<string>& res, string& curr) {
        if (n == 0) {
            res.push_back(curr);
            return;
        }
        curr.push_back('1');
        fun(n-1, res, curr);
        curr.pop_back();
        if (curr.empty() || curr.back() == '1') {
            curr.push_back('0');
            fun(n-1, res, curr);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        string curr;
        fun(n, res, curr);
        return res;
    }
};