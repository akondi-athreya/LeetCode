class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> mp;
        vector<int> ans(n);

        for (int i = 0 ; i < n ; i++) {
            int cnt = 0;
            if (i > 0 && mp.count(A[i])) {
                cnt++;
            }
            mp[A[i]]++;
            if (i > 0 && mp.count(B[i])) {
                cnt++;
            }
            mp[B[i]]++;
            ans[i] = cnt + (i > 0 ? ans[i-1] : (A[i] == B[i]) ? 1 : 0);
        }
        return ans;
    }
};