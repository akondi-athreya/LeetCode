class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t pos = word.find(ch);
        if (pos != string::npos) {
            string ans = "";
            int i = 0;
            while (word[i] != ch) {
                ans += word[i];
                i++;
            }
            ans += word[i];
            string res = "";
            for (int i = ans.length() - 1; i >= 0; i--) res += ans[i];
            for (int j = pos + 1; j < word.length(); j++) {
                res += word[j];
            }
            return res;
        }
        return word;
    }
};