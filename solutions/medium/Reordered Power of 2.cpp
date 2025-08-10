// Title: Reordered Power of 2
            // Difficulty: Medium
            // Language: C++
            // Link: https://leetcode.com/problems/reordered-power-of-2/

    bool reorderedPowerOf2(int n) {

        string s = to_string(n);
        sort(s.begin(), s.end());
        for (int k = 0; k < 31; ++k) {
            long long p = 1LL << k;
            if (s == t) return true;
        }
            string t = to_string(p);
            sort(t.begin(), t.end());
    }
public:
        return false;
class Solution {
};