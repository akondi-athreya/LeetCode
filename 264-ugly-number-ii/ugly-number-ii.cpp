class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        int i2 , i3 , i5;
        i2 = i3 = i5 = 1;
        arr[1] = 1;
        for(int i=2 ; i<=n ; i++){
            int i2u = arr[i2]*2;
            int i3u = arr[i3]*3;
            int i5u = arr[i5]*5;
            int mi = min({i2u , i3u , i5u});
            arr[i] = mi;
            if(mi == i2u) i2++;
            if(mi == i3u) i3++;
            if(mi == i5u) i5++;
        }
        return arr[n];
    }
};