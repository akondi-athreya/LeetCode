class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int pro = 0;

        int n = prices.size();
        for (int i = 0 ; i < n ; i++) {
            if (mi <= prices[i]) {
                pro = max(pro, prices[i] - mi);
            }
            else {
                mi = prices[i];
            }
        }
        return pro;
    }
};