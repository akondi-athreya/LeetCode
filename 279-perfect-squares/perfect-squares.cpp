class Solution {
public:
    int numSquares(int n) {
        vector<int>all;
        int cur=1;
        while(1){
            if(cur*cur<=n){
                all.push_back(cur*cur);
                cur++;
            }
            else{
                break;
            }
        }
        vector<int>dp(n+1,n+1);
        dp[0]=0;
        for(auto c:all){
            for(int sum=0;sum<=n;sum++){
                if(sum+c<=n){
                    dp[sum+c]=min(dp[sum+c],dp[sum]+1);
                }
                else{
                    break;
                }
            }
        }
        return dp[n];
    }
};