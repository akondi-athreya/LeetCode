class Solution {
public:
    int scoreOfString(string s) {
        long long sum=0;
        for(int i=0 ; i<s.size()-1 ; i++){
            sum += abs((int)s[i]-(int)s[i+1]);
        }
        return sum;
    }
};