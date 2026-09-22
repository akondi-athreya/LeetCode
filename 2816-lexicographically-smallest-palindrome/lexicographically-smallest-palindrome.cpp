class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l <= s.size()/2){
            s[l] = min(s[l], s[r]);
            s[r] = s[l];
            l++; r--;
        }
        return s;
    }
};