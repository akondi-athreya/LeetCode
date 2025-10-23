class Solution {
public:
    bool hasSameDigits(string s) {
        int i = 0;
        string temp = "";
        while (s.size() > 2) {
            temp = "";
            i = 0;
            while(i < s.size()-1) {
                temp += to_string((((int)s[i]) + ((int)s[i+1])) % 10);
                i++;
            }
            s = temp;
        }
        if (s[0] == s[1]) return 1;
        return 0;
    }
};