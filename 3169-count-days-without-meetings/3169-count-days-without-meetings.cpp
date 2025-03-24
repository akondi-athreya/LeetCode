class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        int curr = 0;
        sort(begin(meetings), end(meetings));

        for(auto it : meetings) {
            int start = it[0], end = it[1];
            if(start > curr + 1) {
                ans = ans + start - curr - 1;
            }
            curr = max(curr, end);
        }

        ans += days - curr;
        return ans;
    }
};