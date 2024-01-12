class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i=0
        j=len(numbers)-1
        l=[]
        while(i<j):
            s = numbers[i]+numbers[j]
            if(s==target):
                l.append(i+1)
                l.append(j+1)
                return l
                break
            elif s>target:
                j-=1
            else:
                i+=1
            