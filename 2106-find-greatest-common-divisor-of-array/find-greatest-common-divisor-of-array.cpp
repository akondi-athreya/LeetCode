class Solution {
public:
    int cal_gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return cal_gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int mi = *min_element(begin(nums), end(nums));
        int mx = *max_element(begin(nums), end(nums));
        return cal_gcd(mi, mx);
    }
};