class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        // for (int i = 0 ; i < n-1 ; i++) {
        //     for (int j = i+1 ; j < n ; j++) {
        //         if (prices[i] > prices[j]) continue;
        //         else {
        //             ans = max(ans, prices[j]-prices[i]);
        //         }
        //     }
        // }
        // return ans;
        int i = 1;
        int mi = prices[0];
        while (i < n) {
            int num = prices[i];
            if (num < mi) mi = num;
            else {
                ans = max(ans, num - mi);
            }
            i++;
        }
        return ans;
    }
};


// [7,1,5,3,6,4]
//    |
// 4 => 5