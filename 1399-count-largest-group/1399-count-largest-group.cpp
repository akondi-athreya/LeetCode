class Solution {
public:
    int fun(int x) {
        int ans = 0;
        while (x > 0) {
            ans += (x%10);
            x /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        map<int, vector<int>> mp;
        for (int i = 1 ; i <= n ; i++) {
            int x = fun(i);
            mp[x].push_back(i);
        }

        int mx = 0;
        int cnt = 0;
        
        for (auto it : mp) {
            int curr = it.second.size();
            if (curr > mx) {
                mx = curr;
                cnt = 1;
            }
            else if (curr == mx) cnt++;
        }
        
        return cnt;
    }
};