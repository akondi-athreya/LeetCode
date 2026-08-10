class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        int n = s.size();
        for (int i = n - 1 ; i >= 0 ; ) {
            if (s[i] == '#') {
                int num = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                result += (char)('a' + num - 1);
                i -= 3;
            } else {
                int num = s[i] - '0';
                result += (char)('a' + num - 1);
                i -= 1;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};