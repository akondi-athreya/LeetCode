class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0;
        unordered_set<int> st;
        
        for (int x : nums) {
            if (st.count(x - diff) && st.count(x - 2 * diff)) {
                cnt++;
            }
            st.insert(x);
        }
        
        return cnt;
    }
};