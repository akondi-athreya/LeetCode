class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        if(n==1) return true;
        if(n%4==0) return isPowerOfFour(n>>2);
        else return false;
    }
};