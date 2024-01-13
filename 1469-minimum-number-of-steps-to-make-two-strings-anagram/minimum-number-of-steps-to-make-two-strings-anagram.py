class Solution:
    def minSteps(self, s: str, t: str) -> int:
        lit1=list(s)
        lit2=list(t)
        lit3=set(lit1)
        lit4=set(lit2)
        print(len(lit3))
        if(len(lit3)==1 and len(lit4)==1):
            return len(lit1)
        
        for i in lit1:
            if i in lit2:
                lit2.remove(i)
        return len(lit2)