class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int mx = 0;
        for (int it : gain) {
            curr += it;
            mx = max(mx, curr);
        }
        return mx;
    }
};