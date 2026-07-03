class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int lf[26] = {0};
        for (char ch : licensePlate) {
            if (isalpha(ch)) lf[tolower(ch) - 'a']++;
        }
        string res;
        for (int i = 0 ; i < words.size() ; i++) {
            int freq[26] = {0};
            for (char ch : words[i]) freq[ch-'a']++;

            bool flag = true;
            for (int j = 0 ; j < 26 ; j++) {
                if (lf[j] > freq[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag && (res.empty() || words[i].size() < res.size())) res = words[i];
        }
        return res;
    }
};