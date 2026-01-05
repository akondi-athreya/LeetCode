class Solution {
public:
    int dp[101][101][601];
    int fun(vector<pair<int, int>>& cnt , int m, int n, int i) {
        if (i >= cnt.size() || (m == 0 && n == 0)) return 0;

        if (dp[m][n][i] != -1) return dp[m][n][i];

        int take = 0;
        if (cnt[i].first <= m && cnt[i].second <= n) {
            take += 1 + fun(cnt, m-cnt[i].first, n-cnt[i].second, i+1);
        }
        int skip = fun(cnt, m, n, i+1);

        return dp[m][n][i] = max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> cnt;
        int z = 0, o = 0;
        for (int i = 0 ; i < strs.size() ; i++) {
            for (char ch : strs[i]) {
                if (ch == '0') z++;
                else o++;
            }
            cnt.push_back({z, o});
            z = 0, o = 0;
        }

        memset(dp, -1, sizeof(dp));

        return fun(cnt, m, n, 0);
    }
};