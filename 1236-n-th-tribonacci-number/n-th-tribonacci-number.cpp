class Solution {
public:
    int NfN(int n , vector<int> &dp){
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        if(dp[n] != -1){
            return dp[n];
        }
        if(dp[n] == -1){
            NfN(n-1 , dp) + NfN(n-2 , dp) + NfN(n-3 , dp);
        }
        dp[n] = dp[n-1] + dp[n-2] + dp[n-3];
        return dp[n];
    }
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        vector<int> dp(n+1,-1);
        return NfN(n , dp);
    }
};