class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i=0 ; i<arr2.size() ; i++) mp[arr2[i]]=0;
        vector<int> res , v;
        for(int i=0 ; i<arr1.size() ; i++){
            if(mp.find(arr1[i]) != mp.end()) mp[arr1[i]]++;
            else v.emplace_back(arr1[i]);
        }
        sort(v.begin() , v.end());
        for(int i=0 ; i<arr2.size() ; i++){
            for(int j=0 ; j<mp[arr2[i]] ; j++){
                res.emplace_back(arr2[i]);
            }
        }
        for(int i=0 ; i<v.size() ; i++) res.emplace_back(v[i]);
        return res;
        
    }
};