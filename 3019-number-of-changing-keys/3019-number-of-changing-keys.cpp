class Solution {
public:
    int countKeyChanges(string s) {
        if (s.empty()) return 0;
        
        int cnt = 0;

        for (int i = 1 ; i < s.size() ; i++) {
            if (tolower(s[i]) != tolower(s[i-1])) {
                cnt++;
            }
        }
        return cnt;
    }
};