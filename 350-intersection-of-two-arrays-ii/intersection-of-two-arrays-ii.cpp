class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1 , mp2;
        vector<int> v;
        for(int i=0 ; i<nums1.size() ; i++) mp1[nums1[i]]++;
        for(int i=0 ; i<nums2.size() ; i++) mp2[nums2[i]]++;
        for(auto it : mp1){
            if(mp2.find(it.first) != mp2.end()){
                for(int i=0 ; i<min(it.second , mp2[it.first]) ; i++){
                    v.emplace_back(it.first);
                }
            }
        }
        return v;
    }
};