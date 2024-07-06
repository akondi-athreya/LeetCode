class Solution {
public:
    int passThePillow(int n, int time) {
        int r = time/(n-1);
        int ans = 0;
        if(r % 2 == 0) ans = (1+time%(n-1));
        else ans = (n-time%(n-1));
        return ans;
    }
};