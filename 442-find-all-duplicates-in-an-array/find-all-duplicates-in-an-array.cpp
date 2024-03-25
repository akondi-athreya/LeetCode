class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        vector<int> v;
        for(auto it : mp){
            if(it.second >=2){
                v.emplace_back(it.first);
            }
        }
        return v;
    }
};