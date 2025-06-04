class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int a = 1;
        int b = 2;
        int curr;
        for(int i = 3; i <= n; ++i) {
            curr = a + b;
            a = b;
            b = curr;
        }
        return b;
    }
};