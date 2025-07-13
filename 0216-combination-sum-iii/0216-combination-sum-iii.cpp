class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int> path, int index, int num_size, int sum) {
        if (num_size == 0 && sum == 0) {
            ans.push_back(path);
            return;
        }
        if (num_size == 0 && sum != 0) {
            return;
        }
        for (int i = index; i <= 9; i++) {
            int num = i;
            if (num > sum) break;
            path.push_back(num);
            fun(ans, path, i + 1, num_size - 1, sum - num);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        fun(ans, path, 1, k, n);
        return ans;
    }
};