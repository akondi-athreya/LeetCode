class Solution {
public:
    void fun(int i , int n , vector<int>&arr , vector<vector<int>>&ans , vector<int>&v){
        if(i == arr.size()){
            if(n == 0){
                ans.push_back(v);
            }
            return;
        }
        if(arr[i] <= n){
            v.push_back(arr[i]);
            fun(i , n-arr[i] , arr , ans , v);
            v.pop_back();
        }
        fun(i+1 , n , arr , ans , v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        fun(0 , target , candidates , ans , v);
        return ans;
    }
};