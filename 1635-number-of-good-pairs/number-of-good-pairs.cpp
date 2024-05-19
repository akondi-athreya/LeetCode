class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int , int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        int sum=0 , n;
        for(auto it : mp){
            n = it.second;
            if(n >= 2) sum+= ((n*(n-1))/2);
        }
        return sum;
    }
};