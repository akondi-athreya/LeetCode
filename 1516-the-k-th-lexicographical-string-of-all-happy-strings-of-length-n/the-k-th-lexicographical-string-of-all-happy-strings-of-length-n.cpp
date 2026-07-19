class Solution {
public:
    void fun(int n, string curr, vector<string>&v) {
        if (curr.size() == n) {
            v.emplace_back(curr);
            return;
        }
        for (char ch = 'a' ; ch <= 'c' ; ch++) {
            if (curr.size() > 0 && curr.back() == ch) continue;

            fun(n, curr+ch, v);
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> v;
        fun(n, curr, v);
        if (v.size() < k) return "";
        return v[k-1];
    }
};