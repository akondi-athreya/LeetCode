int searchInsert(int* nums, int numsSize, int target){
    long long int low=0;
    long long int high=numsSize-1;
    long long int mid;
    if(target > nums[high])
    {
        return numsSize;
    }
    else if(target < nums[low])
    {
        return 0;
    }
    while(low<=high)
    {
        mid=(low+high) >> 1;
        if(target == nums[mid])
        {
            return mid;
        }
        else if(target < nums[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}