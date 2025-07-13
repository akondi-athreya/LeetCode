class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> st;
    vector<int> temp;
    void fun(vector<int> &v, int i, int n, vector<int> &vec) {
        if (i == n) {
            temp = vec;
            sort(begin(temp), end(temp));
            if(st.find(temp) != st.end()) return;
            res.push_back(temp);
            st.insert(temp);
            return;
        }
        fun(v, i + 1, n, vec);
        vec.push_back(v[i]);
        fun(v, i + 1, n, vec);
        vec.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> vec;
        fun(nums, 0, nums.size(), vec);
        vector<vector<int>> ans = res;
        res.clear();
        return ans;
    }
};