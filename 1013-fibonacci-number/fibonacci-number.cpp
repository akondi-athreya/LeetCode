class Solution {
public:
    /* int fsum(int n){
        if(n<=1){
            return n;
        }
        else{
            return fsum(n-1)+fsum(n-2);
        }
    } */
    int fsum(int n , vector<int>&dp){
        dp[0] = 0;
        dp[1] = 1;
        if(dp[n] != -1){
            return dp[n];
        }
        if(dp[n] == -1){
            fsum(n-1 , dp) + fsum(n-1 , dp);
        }
        dp[n] = dp[n-1] + dp[n-2];
        return dp[n];
    }
    int fib(int n) {
        // return fsum(n);
        if(n==0) return 0;
        vector<int> dp(n+1,-1);
        return fsum(n , dp);
    }
};