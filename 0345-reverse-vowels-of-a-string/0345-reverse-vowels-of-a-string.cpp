class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        unordered_set<char> st = {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };

        while (i < j) {
            while (i < j && !st.count(s[i])) i++;
            while (i < j && !st.count(s[j])) j--;

            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};