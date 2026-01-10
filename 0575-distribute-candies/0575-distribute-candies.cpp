class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        int n = candyType.size();
        for (int i = 0 ; i < n ; i++) {
            st.insert(candyType[i]);
        }
        n /= 2;
        if (n < st.size()) return n;
        else return st.size();
    }
};