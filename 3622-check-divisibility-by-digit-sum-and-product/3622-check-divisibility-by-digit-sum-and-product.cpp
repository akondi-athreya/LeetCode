class Solution {
public:
    bool checkDivisibility(int n) {
        int su = 0, pro = 1;
        int temp = n;
        while (temp > 0) {
            int dig = temp % 10;
            su += dig;
            pro *= dig;
            temp /= 10;
        }
        return (n % (su + pro) == 0);
    }
};