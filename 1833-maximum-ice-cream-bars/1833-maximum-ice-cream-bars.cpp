class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int ans = 0;
        int i = 0;
        while (i < costs.size()) {
            if (coins - costs[i] >= 0) {
                coins -= costs[i];
                ans++;
            }
            i++;
            if (coins <= 0) return ans;
        }
        return ans;
    }
};