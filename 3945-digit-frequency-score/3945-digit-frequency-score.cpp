class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> v(10, 0);
        int su = 0;
        while (n > 0) {
            v[n%10]++;
            n/=10;
        }
        for (int i = 0 ; i < 10 ; i++) {
            su += (i * v[i]);
        }
        return su;
    }
};