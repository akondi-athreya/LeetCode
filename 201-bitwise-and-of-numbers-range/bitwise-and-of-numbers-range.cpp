class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int x = right;
        while(right>left){
            x = right & (right-1);
            right=x;
        }
        return x;

    }
};