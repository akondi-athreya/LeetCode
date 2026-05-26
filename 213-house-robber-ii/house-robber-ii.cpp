class Solution {
public:
    int fun (vector<int>& v) {
        int n = v.size();

        long long int prev = v[0];
        long long int prev2 = 0;

        for (int i = 1 ; i < n ; i++) {
            long long int pick = v[i];

            if (i > 1) pick += prev2;

            long long int nonPick = prev;

            long long int curr = max(pick, nonPick);
            
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> a, b;
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        for (int i = 0 ; i < n ; i++) {
            if (i != 0) a.emplace_back(nums[i]);
            if (i != n-1) b.emplace_back(nums[i]);
        }
        return max(fun(a), fun(b));
    }
};