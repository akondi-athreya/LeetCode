class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int> s;
        int i=0;
        int j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                s.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
        }
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};