class Solution {
public:
    vector<vector<int>> res;
    void fun(vector<int> &v, int i, int n, vector<int> &vec) {
        if (i == n) {
            res.push_back(vec);
            return;
        }
        fun(v, i + 1, n, vec);
        vec.push_back(v[i]);
        fun(v, i + 1, n, vec);
        vec.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        fun(nums, 0, nums.size(), vec);
        vector<vector<int>> ans = res;
        res.clear();
        return ans;
    }
};