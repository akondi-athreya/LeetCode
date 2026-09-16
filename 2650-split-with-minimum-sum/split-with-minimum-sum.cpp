class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(begin(s), end(s));
        string a = "", b = "";
        bool flag = true;
        for (char& ch : s) {
            if (flag) a += ch;
            else b += ch;
            flag = !flag;
        }
        return stoi(a) + stoi(b);
    }
};