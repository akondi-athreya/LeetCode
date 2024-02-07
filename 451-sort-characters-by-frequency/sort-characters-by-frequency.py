class Solution:
    def frequencySort(self, s: str) -> str:
        dict1={}
        for i in s:
            if i in dict1:
                dict1[i]+=1
            else:
                dict1[i]=1
        k=list(dict1)
        print(dict1)
        print(k)
        l1=[]
        l2=[]
        for i in k:
            if i in dict1:
                l2.append(dict1[i])
        l2.sort()
        for i in l2:
            for j in k:
                if j in dict1:
                    if  i == dict1[j]:
                        l1.append(j*dict1[j])
                        del dict1[j]
        l1.reverse()
        st="".join(l1)
        return st