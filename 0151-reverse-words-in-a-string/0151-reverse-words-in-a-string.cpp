class Solution {
public:
    string reverseWords(string s) {
        string str="";
        vector<string> ans;
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == ' ') {
                if(str.size() > 0) {
                    ans.emplace_back(str);
                    str = "";
                }
                else continue;
            }
            else str += s[i];
        }
        if(str.size() > 0) {
            ans.emplace_back(str);
        }
        str = "";
        reverse(begin(ans), end(ans));
        for(int i=0 ; i<ans.size() ; i++) {
            str += ans[i];
            if(i != ans.size()-1) str += " ";
        }
        return str;
    }
};