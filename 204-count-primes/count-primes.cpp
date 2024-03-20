class Solution {
public:
    int isprime(int n){
        int cnt=0;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p*p < n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p){
                    prime[i] = false;
                }
            }
        }
        for (int p = 2; p < n; p++){
            if (prime[p]) cnt++;
        }
        return cnt;
    }
    int countPrimes(int n) {
        if(n==0 || n==1 || n==2) return 0;
        int cnt=0;
        cnt = isprime(n);
        return cnt;
    }
};