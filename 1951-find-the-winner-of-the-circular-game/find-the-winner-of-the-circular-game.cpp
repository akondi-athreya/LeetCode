class Solution {
public:
    int fun(int n , int k){
        if(n==1) return 0;
        int ans = fun(n-1 , k);
        ans = (ans + k)%n;
        return ans;
    }
    int findTheWinner(int n, int k) {
        int ans = fun(n,k);
        return ans+1;
    }
};