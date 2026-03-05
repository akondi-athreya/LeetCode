class Solution {
public:
    int minOperations(string s) {
        int cnt1 = 0, cnt2 = 0;
        int n = s.size();
        string s1 = "", s2 = "";
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (flag) {
                s1 += "0";
                s2 += "1";
                flag = !flag;
            } else {
                s1 += "1";
                s2 += "0";
                flag = !flag;
            }
        }
        for (int i = 0 ; i < n ; i++) {
            if (s[i] != s1[i]) cnt1++;
            if (s[i] != s2[i]) cnt2++;
        }
        return min(cnt1, cnt2);
    }
};