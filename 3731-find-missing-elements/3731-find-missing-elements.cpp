class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums));
        int mi = *min_element(begin(nums), end(nums));

        vector<int> v;
        unordered_set<int> st(nums.begin(), nums.end());
        
        for (int i = mi ; i <= mx ; i++) {
            if (!st.count(i)) {
                v.push_back(i);
            }
        }
        
        return v;
    }
};