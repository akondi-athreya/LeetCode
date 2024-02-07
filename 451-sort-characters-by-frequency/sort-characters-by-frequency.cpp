class Solution {
public:
    string rearrangeString(const string& input) {
            map<char, int> charCount;
            for (char ch : input) {
                charCount[ch]++;
            }
            vector<pair<char, int>> charFreqVec(charCount.begin(), charCount.end());
            sort(charFreqVec.begin(), charFreqVec.end(), [](const auto& a, const auto& b) {
                return (a.second > b.second) || (a.second == b.second && a.first < b.first);
            });
            string result;
            for (const auto& pair : charFreqVec) {
                result.append(pair.second, pair.first);
            }
            return result;
        }
    string frequencySort(string s) {
        return rearrangeString(s);
    }
};