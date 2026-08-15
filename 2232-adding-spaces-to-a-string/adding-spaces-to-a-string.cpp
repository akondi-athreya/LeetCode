class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        string t(n + m, ' ');
        
        int j = 0;
        for (int i = 0 ; i < n ; i++) {
            if (j < m && i == spaces[j]) {
                t[i+j] = ' '; 
                j++;
            }
            t[i+j] = s[i];
        }
        return t;
    }
};