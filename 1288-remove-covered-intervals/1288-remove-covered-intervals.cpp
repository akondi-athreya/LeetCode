class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](vector<int>&a, vector<int>&b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int cnt = 0, mx = 0;

        for (auto& it : intervals) {
            if (it[1] > mx) {
                cnt++;
                mx = it[1];
            }
        }
        return cnt;
    }
};