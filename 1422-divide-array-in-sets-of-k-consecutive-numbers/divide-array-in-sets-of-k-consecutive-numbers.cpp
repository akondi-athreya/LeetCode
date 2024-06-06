class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;
        unordered_map<int , int> mp;
        for(int i : nums) mp[i]++;
        for(int i : nums){
            int s = i;
            while(mp[s]) s--;
            while(s <= i){
                while(mp[s]){
                    for(int j=s ; j<s+k ; j++){
                        if(!mp[j]) return false;
                        mp[j]--;
                    }
                }
                s++;
            }
        }
        return true;
    }
};