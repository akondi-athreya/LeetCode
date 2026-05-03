class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string n = s + s;

        return n.find(goal) < n.length();
    }
};