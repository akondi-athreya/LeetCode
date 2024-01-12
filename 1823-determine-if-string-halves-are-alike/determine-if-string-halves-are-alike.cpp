class Solution {
public:
    int countqw(string str){
        int cnt=0;
        for(int i=0 ; i<str.size() ; i++){
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' ||str[i]=='u' || str[i]=='A' ||str[i]=='E' || str[i]=='I' ||str[i]=='O' || str[i]=='U' ){
                cnt+=1;
            }
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        string a,b;
        int n = s.size()/2;
        a = s.substr(0,n);
        b = s.substr(n);
        // cout<<a<<" "<<b;
        int lcnt = countqw(a);
        int rcnt = countqw(b);
        if(lcnt==rcnt){
            return true;
        }
        else{
            return false;
        }
    }
};