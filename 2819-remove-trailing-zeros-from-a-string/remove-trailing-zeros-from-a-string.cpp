class Solution {
public:
    string removeTrailingZeros(string num) {
        // reverse(begin(num), end(num));
        // int n = num.size();
        // int cnt = 0;
        // for (char ch : num) {
        //     if (ch != '0') {
        //         break;
        //     }
        //     else cnt++;
        // }
        // string ans = num.substr(cnt, n-cnt);
        // reverse(begin(ans), end(ans));
        // return ans;

        int n = num.size();
        int cnt = 0;
        for (int i = n-1 ; i >= 0 ; i--) {
            if (num[i] != '0') break;
            else cnt++;
        }
        return num.substr(0, n-cnt);
    }
};