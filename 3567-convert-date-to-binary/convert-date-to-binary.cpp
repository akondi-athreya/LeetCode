class Solution {
public:
    string to_bin(int n) {
        string ans = "";
        while (n > 0 || n != 0) {
            ans += (n&1) ? '1' : '0';
            n = n >> 1;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
    string convertDateToBinary(string date) {
        string y = date.substr(0, 4);
        string m = date.substr(5, 2);
        string d = date.substr(8, 2);
        int yy = stoi(y);
        int mm = stoi(m);
        int dd = stoi(d);
        return to_bin(yy)+"-"+to_bin(mm)+"-"+to_bin(dd);
    }
};