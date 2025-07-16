class Solution {
public:
    bool isBalanced(string num) {
        int s1 = 0, s2 = 0;
        for(int i = 0 ; i < num.size() ; i++) {
            if(i&1) s1 += int(num[i]) - '0';
            else s2 += int(num[i]) - '0';
        }
        return s1 == s2;
    }
};