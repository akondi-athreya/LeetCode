class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int l = 0,r = 0;
        while(r < n-1) {
            int dis = 0;
            for(int i = l ; i <= r ; i++) {
                dis = max(dis, i + nums[i]);
            }
            l = r+1;
            r = dis;
            ans++;
        }
        return ans;
    }
};