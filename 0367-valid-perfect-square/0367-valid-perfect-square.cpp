class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num/2;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(mid * mid == num) return true;
            else if(mid * mid > num) high = mid-1;
            else low = mid+1;
        }
        if(num == 1) return true;
        return false;
    }
};