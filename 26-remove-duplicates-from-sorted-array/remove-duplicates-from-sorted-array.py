class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=0
        j=i+1
        while(i<=j):
            if len(nums)==1:
                return 1
                break
            elif len(nums)==2:
                if nums[0]==nums[1]:
                    return 1
                    break
                else:
                    return 2
                    break
            elif nums[i]==nums[j]:
                if j==len(nums)-1:
                    if nums[i]==nums[j]:
                        del(nums[j])
                        return len(nums)
                        break
                    else:
                        return len(nums)
                        break
                else:
                    del(nums[j])
            elif nums[i]!=nums[j]:
                if j==len(nums)-1:
                    return len(nums)
                    break
                else:
                    i+=1
                    j=i+1