class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int freq[26] = {0};
        for (char& c : allowed) {
            freq[c - 'a'] = 1;
        }
        
        int count = 0;
        for (string& word : words) {
            int flag = 1;
            for (char& c : word) {
                if (freq[c - 'a'] == 0) {
                    flag = 0;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};