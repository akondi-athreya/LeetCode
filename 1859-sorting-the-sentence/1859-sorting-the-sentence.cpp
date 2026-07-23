class Solution {
public:
    string sortSentence(string s) {
        map<int, string> mp;
        string ns = "";
        int n = s.size();
        for (int i = 0 ; i < n ; i++) {
            if (isdigit(s[i])) {
                int pos = s[i] - '0';
                mp[pos] = ns;
                ns = "";
                i++;
            } else if (s[i] != ' ') {
                ns += s[i];
            }
        }
        ns = "";
        for (auto it : mp) {
            ns += it.second + " ";
        }
        return ns.substr(0, ns.size()-1);
    }
};