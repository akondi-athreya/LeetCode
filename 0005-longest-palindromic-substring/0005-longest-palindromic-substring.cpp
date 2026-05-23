class Solution {
public:
    int dp[1001][1001];
    bool fun(string& s, int i, int j) {
        if (i >= j) {
            return 1;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = fun(s, i+1, j-1);
        }
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();

        memset(dp, -1, sizeof(dp));

        int idx = -1;
        int mx = INT_MIN;

        for (int i = 0 ; i < n ; i++) {
            for (int j = i ; j < n ; j++) {
                if (fun(s, i, j)) {
                    if (j-i+1 > mx) {
                        mx = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, mx);
    }
};