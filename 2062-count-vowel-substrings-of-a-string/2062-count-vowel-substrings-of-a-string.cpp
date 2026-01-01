class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = i ; j < n ; j++) {
                set<char> st;
                bool flag = true;
                for (int k = i ; k <= j ; k++) {
                    if (word[k] == 'a' || word[k] == 'e' || word[k] == 'i' || word[k] == 'o' || word[k] == 'u') {
                        // s += word[k];
                        st.insert(word[k]);
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) if (st.size() == 5) cnt++;
            }
        }
        return cnt;
    }
};