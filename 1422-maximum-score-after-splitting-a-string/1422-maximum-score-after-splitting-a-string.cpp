class Solution {
public:
    int maxScore(string s) {
        int ocnt = 0;
        int zcnt = 0;
        int ans = INT_MIN;

        for (int i=0 ; i<s.size()-1 ; i++) {
            if (s[i] == '1') ocnt++;
            else zcnt++;
            
            ans = max(ans, zcnt - ocnt);
        }
        
        if (s[s.size()-1] == '1') ocnt++;
        
        return ans + ocnt;
    }
};