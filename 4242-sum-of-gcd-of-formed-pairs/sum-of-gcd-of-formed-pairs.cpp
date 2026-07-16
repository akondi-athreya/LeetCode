class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx;
        int p = INT_MIN;
        for (int num : nums) {
            p = max(p, num);
            mx.emplace_back(p);
        }
        vector<int> pgcd;
        for (int i = 0 ; i < n ; i++) {
            pgcd.emplace_back(gcd(nums[i], mx[i]));
        }
        sort(pgcd.begin(), pgcd.end());

        long long ans = 0;
        int l = 0 , r = n-1;
        while (l < r) {
            ans += gcd(pgcd[l], pgcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};