class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;

        while (columnNumber) {
            columnNumber--;
            s = s + (char)((columnNumber) % 26 + 'A');
            columnNumber /= 26;
        }

        reverse(begin(s), end(s));
        return s;
    }
};