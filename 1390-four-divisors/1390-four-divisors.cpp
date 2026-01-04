class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int sum = 0;
            int cnt = 0;
            for (int i = 1 ; i * i <= x ; i++) {
                if (x % i == 0) {
                    int e = x / i;
                    cnt++;
                    sum += i;
                    if (i != e) {
                        cnt++;
                        sum += e;
                    }
                    if (cnt > 4) break;
                }
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};