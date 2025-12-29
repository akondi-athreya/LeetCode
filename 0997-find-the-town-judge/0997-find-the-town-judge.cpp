class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> v(n+1);
        for (int i = 0 ; i < trust.size() ; i++) {
            v[trust[i][0]].second++;
            v[trust[i][1]].first++;
        }
        for (int i = 1 ; i < v.size() ; i++) {
            int fi = v[i].first;
            int si = v[i].second;
            if (fi == n-1 && si == 0) return i;
        }
        return -1;
    }
};