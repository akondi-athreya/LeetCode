class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> st;

        int n = nums.size();
        int m = nums[0].size();
        for (int i = 0 ; i < n ; i++) {
            st.insert(stoi(nums[i], 0, 2));
        }
        string res = "";

        for (int i = 0 ; i <= n ; i++) {
            if (!st.count(i)) {
                res = bitset<16>(i).to_string();

                return res.substr(16-n, n);
            }
        }
        return "";
    }
};