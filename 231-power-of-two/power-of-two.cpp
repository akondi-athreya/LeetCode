class Solution {
public: 
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if((n&1)==1){
            if(n==1) return true;
            else return false;
        }
        return isPowerOfTwo(n>>1);
    }
};