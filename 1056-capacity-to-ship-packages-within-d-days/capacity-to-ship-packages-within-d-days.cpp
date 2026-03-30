class Solution {
public:
    int fun(vector<int>& weights, int f) {
        int d = 1;
        int res = 0;
        for (int we : weights) {
            if (res + we > f) {
                d++;
                res = we;
            }
            else {
                res += we;
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mi = *max_element(begin(weights), end(weights));
        int mx = accumulate(begin(weights), end(weights), 0);

        while (mi < mx) {
            int mid = mi + (mx-mi) / 2;
            int need = fun(weights, mid);

            if (need <= days) {
                mx = mid;
            }
            else {
                mi = mid+1;
            }
        }
        return mi;
    }
};