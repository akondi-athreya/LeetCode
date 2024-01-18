class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        //vector<int> pre;
        pre.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++){
            int data = nums[i]+pre[i-1];
            pre.push_back(data);
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return pre[right];
        }
        else{
            int res = (pre[right])-(pre[left-1]);
            return res;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */