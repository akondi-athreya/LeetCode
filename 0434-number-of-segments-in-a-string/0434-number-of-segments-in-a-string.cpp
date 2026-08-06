class Solution {
public:
    int countSegments(string s) {
        int cnt = 0, n = s.size();
        string ss = "";
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == ' ') {
                if (ss.size() > 0) {
                    ss = "";
                    cnt++;
                }
            }
            else {
                ss += s[i];
            }
        }
        return cnt + (ss.size() > 0 ? 1 : 0);
    }
};