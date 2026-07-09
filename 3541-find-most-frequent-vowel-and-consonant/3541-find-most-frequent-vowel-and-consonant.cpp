class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> v(26, 0);
        for (char& ch : s) {
            v[ch-'a']++;
        }
        int a = 0, b = 0;
        for (int i = 0 ; i < 26 ; i++) {
            char ch = i + 'a';
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                a = max(a, v[i]);
            }
            else {
                b = max(b, v[i]);
            }
        }
        return a+b;
    }
};