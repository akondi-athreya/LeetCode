class Solution {
public:
    long long fun(vector<int>& v, long long mid) {
        long long cnt = 0;
        for (int i = 0 ; i < v.size() ; i++) {
            cnt += (v[i] + mid - 1) / mid;
            if (cnt > 1e18) break;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(), piles.end());
        long long ans = 1;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long res = fun(piles, mid);

            if (res <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};