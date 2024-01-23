class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        
        while(x!=0){
            long dig = x%10;
            rev = rev*10+dig;
            x/=10;
        }
        if(rev>pow(2,31)-1){
            return 0;
        }
        else if(rev<pow(-2,31)){
            return 0;
        }
        if(x<0){
            rev *= -1;
            return rev;
        }
        else{
            return rev;
        }
    }
};