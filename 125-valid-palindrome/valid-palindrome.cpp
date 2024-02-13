class Solution {
public:
    bool rev(int i , string& s){
        if(i >= s.size()/2) return true;
        if(s[i] !=  s[s.size()-1-i]) return false;
        else return rev(i+1 , s);
    }
    bool isPalindrome(string s) {
        for(char &c : s){
            c = tolower(c);
        }
        s.erase(remove_if(s.begin(),s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());
        
        return rev(0 , s);
    }
};