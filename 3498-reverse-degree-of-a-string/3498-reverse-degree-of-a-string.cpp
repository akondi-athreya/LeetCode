class Solution {
public:
    int reverseDegree(string s) {
        int pro = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            int d = (('z' - s[i]) + 1);
            pro += (d * (i+1));
        }
        return pro;
    }
};