class Solution {
public:
    void fun(int index , int n , vector<int> &arr , vector<vector<int>> &ans , vector<int>&v){
        if(n==0){
            ans.push_back(v);
            return;
        }
        for(int i=index ; i<arr.size() ; i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i] > n) break;
            v.push_back(arr[i]);
            fun(i+1 , n-arr[i] , arr , ans , v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        fun(0 , target , candidates , ans , v);
        return ans;
    }
};