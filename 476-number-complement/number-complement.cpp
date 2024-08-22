class Solution {
public:
    int findComplement(int num) {
        int i = 0;
        int c = 0;
        while(num){
            if(!(num&1)){
                c |= (1<<i);
            }
            num>>=1;
            i++;
        }
        return c;
    }
};