class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        for (int num : arr) st.insert(num);

        unordered_map<int, int> mp;
        int r = 1;
        for (int num : st) {
            mp[num] = r;
            r++;
        }
        vector<int> ans;
        for (int num : arr) {
            ans.emplace_back(mp[num]);
        }
        return ans;
    }
};