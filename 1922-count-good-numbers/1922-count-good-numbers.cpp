int mod = 1e9+7;
#define ll long long
class Solution {
public:
    int fun(ll b, ll e, ll ans) {
        if(e == 0) return ans;
        if(e&1) return fun(b, e-1, (ans*b)%mod);
        else return fun((b*b)%mod, e/2, ans);
    }
    int countGoodNumbers(long long n) {
        ll ans = fun(20, n/2, 1);
        return (n&1) ? (ans * 5) % mod : ans;
    }
};