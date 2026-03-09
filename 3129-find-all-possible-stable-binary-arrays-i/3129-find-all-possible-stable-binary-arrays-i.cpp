class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][2];
    int solve(int ol, int zl, bool isOne, int limit) {
        if (ol == 0 && zl == 0) {
            return 1;
        }
        if (dp[ol][zl][isOne] != -1) {
            return dp[ol][zl][isOne];
        }

        int res = 0;
        if (isOne == true) {
            // now 0's turn
            for (int i = 1; i <= min(zl, limit); i++) {
                res = (res + solve(ol, zl - i, false, limit)) % MOD;
            }
        } else {
            // now 1's turn
            for (int i = 1; i <= min(ol, limit); i++) {
                res = (res + solve(ol - i, zl, true, limit)) % MOD;
            }
        }

        return dp[ol][zl][isOne] = res;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        int a = solve(one, zero, false, limit);
        int b = solve(one, zero, true, limit);

        return (a % MOD + b % MOD) % MOD;
    }
};