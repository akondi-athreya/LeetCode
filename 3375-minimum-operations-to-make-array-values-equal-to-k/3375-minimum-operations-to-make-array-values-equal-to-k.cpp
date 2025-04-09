class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        int cnt = 0;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == k) cnt++;
            else if(nums[i] < k) return -1;
            st.insert(nums[i]);
        }
        if(st.size() == 1 && nums[0] == k) return 0;
        if(cnt > 0) return st.size() - 1;
        return st.size();
    }
};