class Solution {
public:
    int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for(int i=0 ; i<n ; i++){
            int sum=0;
            for(int j=i ; j<n ; j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin() , v.end());
        int sum=0;
        for(int z=left-1 ; z<=right-1 ; z++){
            sum = (sum+v[z]) % M;
        }
        return sum;
    }
};