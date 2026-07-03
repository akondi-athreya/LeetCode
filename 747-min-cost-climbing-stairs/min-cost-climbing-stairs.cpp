class Solution {
public:
    int dp[1001];
    int fun(int i, vector<int>&cost, int n) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int a = cost[i] + fun(i+1, cost, n);
        int b = cost[i] + fun(i+2, cost, n);

        return dp[i] = min(a, b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min(fun(0, cost, n), fun(1, cost, n));
    }
};