class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro=1 , cnt=0 , flag=0;
        vector<int> v;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0){
                cnt++;
                if(cnt==2){
                    flag = 1;
                    break;
                }
            }
            if(nums[i] != 0){
                pro *= nums[i];
            }
        }
        if(flag == 1){
            vector<int> z(nums.size() , 0);
            return z;
        }
        else{
            for(int i=0 ; i<nums.size() ; i++){
                if(cnt==1){
                    if(nums[i] != 0){
                        v.emplace_back(0);
                    }
                    else v.emplace_back(pro);
                }
                else{
                    v.emplace_back(pro/nums[i]);
                }
            }
            return v;
        }
        return {};
    }
};