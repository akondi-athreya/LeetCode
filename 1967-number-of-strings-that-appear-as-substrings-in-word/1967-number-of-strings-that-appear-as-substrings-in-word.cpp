class Solution {
public:
    vector<int> buildlps(string a, int alen) {
        vector<int> lps(alen, 0);
        int len = 0;
        int i = 1;

        while (i < alen) {
            if (a[i] == a[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool fun(string a, string b, int blen) {
        int alen = a.size();
        if (alen > blen) return false;

        vector<int> lps = buildlps(a, alen);

        int i = 0, j = 0;
        while (i < blen) {
            if (a[j] == b[i]) {
                i++;
                j++;
            }
            if (j == alen) return true;
            else if (i < blen && a[j] != b[i]) {
                if (j != 0) j = lps[j-1];
                else i++;
            }
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        int n = patterns.size();
        int m = word.size();
        for (int i = 0 ; i < n ; i++) {
            if (fun(patterns[i], word, m)) ans++;
        }
        return ans;
    }
};