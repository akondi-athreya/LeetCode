class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        if (n == 1) return true;
        int i = 0;
        bool came = false;
        while (i < n) {
            if (s[i] == '1' && !came) {
                came = !came;
            }
            else if (s[i] == '0' && came) continue;
            else if (s[i] == '1' && came && s[i-1] != '1') return false; 
            i++;
        }
        return true;
    }
};