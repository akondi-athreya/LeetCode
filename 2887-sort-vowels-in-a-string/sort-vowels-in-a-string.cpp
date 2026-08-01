class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for (char& ch : s) {
            char nc = tolower(ch);
            if (nc == 'a' || nc == 'e' || nc == 'i' || nc == 'o' || nc == 'u') {
                v.push_back(ch);
            }
        }
        sort(begin(v), end(v));
        reverse(begin(v), end(v));
        for (int i = 0 ; i < s.size() ; i++) {
            char nc = tolower(s[i]);
            if (nc == 'a' || nc == 'e' || nc == 'i' || nc == 'o' || nc == 'u') {
                s[i] = v.back();
                v.pop_back();
            }
        }
        return s;
    }
};