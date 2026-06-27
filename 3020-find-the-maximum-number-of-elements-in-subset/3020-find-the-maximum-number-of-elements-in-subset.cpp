class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> mp;
        for (int num : nums) mp[num]++;
        int ans = 0;

        for (auto [num, frew] : mp) {
            long long x = num;
            int cnt = 0;
            while (mp.count(x) && mp[x]) {
                if (x == 1) cnt += mp[1];
                else if (mp[x] >= 2) cnt += 2;
                else if (mp[x] == 1) {
                    cnt += 1;
                    break;
                }
                mp[x] = 0;
                if (x > 1e6) break;
                x = x*x;
            }
            ans = max(ans, cnt - (!(cnt&1)));
        }
        return ans;
    }
};