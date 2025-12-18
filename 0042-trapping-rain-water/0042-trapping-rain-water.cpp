class Solution {
public:
    int trap(vector<int>& height) {
        vector<long long> left,right;
        long long max = 0;
        for(long long i=0 ; i<height.size() ; i++){
            if(height[i]>=max){
                max=height[i];
            }
            left.push_back(max);
        }
        max = 0;
        for(long long i=height.size()-1 ; i>=0 ; i--){
            if(height[i]>=max){
                max=height[i];
            }
            right.push_back(max);
        }
        reverse(right.begin(),right.end());
        long long sum=0;
        for(long long i=0 ; i<height.size() ; i++){
            sum+=(min(left[i],right[i])-height[i]);
        }
        return sum;
    }
};