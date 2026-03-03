class Solution {
public:
    string fun(string s) {
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }
        return s;
    }
    void rev(string &s) {
        int i = 0 , j = s.size()-1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    char findKthBit(int n, int k) {
        vector<string> v;
        v.push_back("0");
        for (int i = 1 ; i < n ; i++) {
            string str = fun(v[i-1]);
            rev(str);
            v.push_back(v[i-1] + "1" + str);
        }
        if (k <= v[n-1].size()) {
            return v[n-1][k-1];
        }
        return ' ';
    }
};