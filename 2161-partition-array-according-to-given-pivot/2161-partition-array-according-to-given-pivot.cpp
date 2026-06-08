class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> sml, lar;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++) {
            if (nums[i] < pivot) sml.push_back(nums[i]);
            else if (nums[i] > pivot) lar.push_back(nums[i]);
        }
        ans = sml;
        for (int i = 0 ; i < (n - (sml.size() + lar.size())) ; i++) {
            ans.push_back(pivot);
        }
        for (int i = 0 ; i < lar.size() ; i++) {
            ans.push_back(lar[i]);
        }
        return ans;
    }
};