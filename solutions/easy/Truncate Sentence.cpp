// Title: Truncate Sentence
            // Difficulty: Easy
            // Language: C++
            // Link: https://leetcode.com/problems/truncate-sentence/

class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0;
        string ans = "";
        for (char& ch : s) {
            if (ch == ' ') cnt++;
        }
            if (cnt == k) {
                break;
            }
    }
            ans += ch;
        return ans;
};
