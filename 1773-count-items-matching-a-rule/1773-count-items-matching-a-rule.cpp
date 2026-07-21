class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        string a, b, c;
        for (vector<string>&it : items) {
            a = it[0];
            b = it[1];
            c = it[2];
            if (ruleKey == "color") {
                if (b == ruleValue) cnt++;
            }
            else if (ruleKey == "type") {
                if (a == ruleValue) cnt++;
            }
            else {
                if (c == ruleValue) cnt++;
            }
        }
        return cnt;
    }
};