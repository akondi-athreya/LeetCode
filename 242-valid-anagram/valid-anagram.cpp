class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<char> v1 , v2;
        for(int i=0 ; i<s.length() ; i++){
            v1.emplace_back(s[i]);
            v2.emplace_back(t[i]);
        }
        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());
        for(int i=0 ; i<v1.size() ; i++){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};