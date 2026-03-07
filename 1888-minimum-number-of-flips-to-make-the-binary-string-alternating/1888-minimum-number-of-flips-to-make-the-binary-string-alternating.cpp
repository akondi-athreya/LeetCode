class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int ans = INT_MAX;
        int res1 = 0, res2 = 0, i = 0, j = 0;

        while (j < 2*n) {
            int ch1 = (j%2) ? '1' : '0';
            int ch2 = (j%2) ? '0' : '1';

            if (s[j%n] != ch1) res1++;

            if (s[j%n] != ch2) res2++;

            if (j-i+1 > n) {
                ch1 = (i%2) ? '1' : '0';
                ch2 = (i%2) ? '0' : '1';

                if (s[i%n] != ch1) res1--;

                if (s[i%n] != ch2) res2--;

                i++;
            }

            if(j-i+1 == n) {
                ans = min({ans, res1, res2});
            }
            j++;
        }
        return ans;
    }
};