class Solution {
public:
    int maxDepth(string s) {
        int mx = 0 , cnt=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')') cnt--;
            if(mx<cnt) mx=cnt;
        }
        return mx;
    }
};