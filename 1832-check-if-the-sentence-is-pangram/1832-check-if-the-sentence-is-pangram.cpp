class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26, 0);
        for (char ch : sentence) {
            v[ch-'a']++;
        }
        for (int i : v) {
            if (i == 0) return 0;
        }
        return 1;
    }
};