class Solution {
public:
    int integerReplacement(int n) {
        long long x = n;
        int ans = 0;

        while (x != 1) {
            if (x & 1) {
                if (x == 3 || ((x >> 1) & 1) == 0)
                    x--;
                else
                    x++;
            } else {
                x >>= 1;
            }
            ans++;
        }
        return ans;
    }
};