class Solution {
public:
    bool fun(int a, int b) {
        if (abs(a-b) % 2 != 0) return false;

        return true;
    }
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        v[0] = nums[0];
        for (int i = 1 ; i < n ; i++) {
            v[i] = nums[i] + v[i-1];
        }
        int cnt = 0;
        for (int i = 1 ; i < n ; i++) {
            if (fun(v[i-1], v[n-1]-v[i-1])) cnt++;
        }
        return cnt;
    }
};