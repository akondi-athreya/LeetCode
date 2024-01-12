class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        str1 = bin(n)[2:]
        cnt = str1.count('1')
        if n<0:
            cnt-=1
        if cnt==1 and n>0:
            return True
        else:
            return False