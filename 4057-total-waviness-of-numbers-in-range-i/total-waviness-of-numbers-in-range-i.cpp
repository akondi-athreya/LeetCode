class Solution {
public:
    int fun(int n) {
        string s = to_string(n);
        int cnt = 0;
        for (int i = 1 ; i < s.size()-1 ; i++) {
            if ((s[i] > s[i-1] && s[i] > s[i+1]) || (s[i] < s[i-1] && s[i] < s[i+1])) cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for (int i = num1 ; i <= num2 ; i++) {
            cnt += fun(i);
        }
        return cnt;
    }
};