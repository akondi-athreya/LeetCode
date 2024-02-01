class Solution {
public:
    int fsum(int n){
        if(n<=1){
            return n;
        }
        else{
            return fsum(n-1)+fsum(n-2);
        }
    }
    int fib(int n) {
        return fsum(n);
    }
};