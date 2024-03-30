class Solution {
public:
    int fun(vector<int>&v , int k){
        if(k==0) return 0;
        int n , t=0 , d=0 , j=0;
        n=v.size();
        vector<int>dp(20002);
        for(int i=0 ; i<n ; i++){
            if(dp[v[i]]==0){
                d++;
                dp[v[i]]++;
            }
            else dp[v[i]]++;
            if(d <= k) t+=i-j+1;
            else{
                while(j<n && j<=i && d>k){
                    dp[v[j]]--;
                    if(dp[v[j]]==0) d--;
                    j++;
                }
                t+=i-j+1;
            }
        }
        return t;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (fun(nums , k) - fun(nums , k-1));
    }
};