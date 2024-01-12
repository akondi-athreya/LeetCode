class Solution:
    def maxArea(self, height: List[int]) -> int:
        i=0
        j=len(height)-1
        l = []
        while(i<=j):
            a = height[i]
            b = height[j]
            hei = min(a,b)
            wid = j-i
            area = hei*wid
            l.append(area)
            if(a<=b):
                i+=1
            else:
                j-=1
        return max(l)
            

            