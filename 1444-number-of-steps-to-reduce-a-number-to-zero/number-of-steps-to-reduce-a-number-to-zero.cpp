class Solution {
public:
    int fun(int num){
        if(num==0) return 0;
        else if(num%2==0) return 1+fun(num>>1);
        else return 1+fun(num-1);
        return 0;
    }
    int numberOfSteps(int num) {
        return fun(num);
    }
};