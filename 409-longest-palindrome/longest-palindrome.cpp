class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int res=0;
        unordered_map<char , int> freq;
        for(auto it : s) freq[it]++;
        bool odd = false;
        for(auto it : freq){
            if(it.second % 2 == 0) res += it.second;
            else{
                res += it.second-1;
                odd = true;
            }
        }
        return (odd) ? res+1 : res;
    }
};