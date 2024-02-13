class Solution {
public:
    int setBit(long long n ,vector<long long>&dp){
        if(n==0){
            dp[0] = 0;
            return dp[0];
        }
        long long temp = n;
        long long cnt=0;
        while(temp!=0){
            if((temp&1)==1){
                cnt++;
            }
            temp = temp>>1;
        }
        if (dp[n]==-1){
            dp[n] = cnt;
            dp[n-1] = setBit(n-1 , dp);
        }
        return dp[n];
    }
    vector<int> countBits(int n) {
        vector<long long> dp (n+1,-1);
        setBit(n , dp);
        vector<int> ans;
        for (int i=0;i<=n;i++){
            ans.emplace_back(dp[i]);
        }
        return ans;
    }
};