class Solution {
public:
    int n;
    long long solve(int i, vector<vector<int>>&q, vector<long long>&ans) {
        if(i >= n) return 0;

        if(ans[i] != -1) return ans[i];
        long long taken = q[i][0] + solve(i + q[i][1] + 1, q, ans);
        long long not_taken = solve(i+1, q, ans);

        return ans[i] = max(taken, not_taken);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector<long long> ans(n+1, -1);
        return solve(0, questions, ans);
    }
};