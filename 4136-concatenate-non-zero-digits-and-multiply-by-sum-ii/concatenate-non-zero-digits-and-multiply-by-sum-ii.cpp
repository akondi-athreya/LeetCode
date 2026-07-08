class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> nonZeroCnt(n, 0);
        vector<ll> numberUpTo(n, 0);
        vector<ll> digitSumUpTo(n, 0);
        vector<ll> pow10(n+1, 0);

        pow10[0] = 1;
        for (int i = 1 ; i <= n ; i++) {
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        nonZeroCnt[0] = (s[0] != '0') ? 1 : 0;
        for (int i = 1 ; i < n ; i++) {
            int d = s[i]-'0';
            nonZeroCnt[i] = nonZeroCnt[i-1] + ((d != 0) ? 1 : 0);
        }

        numberUpTo[0] = s[0] - '0';
        for (int i = 1 ; i < n ; i++) {
            int d = s[i] - '0';
            if (d != 0) {
                numberUpTo[i] = ((numberUpTo[i-1] * 10) + d) % MOD;
            }
            else {
                numberUpTo[i] = numberUpTo[i-1];
            }
        }

        digitSumUpTo[0] = s[0]-'0';
        for (int i = 1 ; i < n ; i++) {
            int d = s[i]-'0';
            digitSumUpTo[i] = digitSumUpTo[i-1] + d;
        }

        int qSz = queries.size();
        vector<int> ans(qSz);
        for (int i = 0 ; i < qSz ; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ll su = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l-1]);

            ll nb = (l == 0) ? 0 : numberUpTo[l-1];
            int k = nonZeroCnt[r] - ((l == 0) ? 0 : nonZeroCnt[l-1]);

            ll x = (numberUpTo[r] - (nb * pow10[k] % MOD) + MOD) % MOD;
            ans[i] = (int)((x * su)%MOD);
        }
        return ans;
    }
};