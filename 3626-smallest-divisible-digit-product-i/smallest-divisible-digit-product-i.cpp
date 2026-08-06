class Solution {
public:
    int fun(int n) {
        int pro = 1;
        while (n > 0) {
            pro *= (n % 10);
            n /= 10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        for (int i = n ; i <= n+10 ; i++) {
            int nn = fun(i);
            if (nn % t == 0) return i;
        }
        return n;
    }
};