class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        l1 = len(word1)
        l2 = len(word2)
        if l1 != l2: return False
        w1 = set(word1)
        if w1 != set(word2): return False
        wd1 = []
        wd2 = []
        for i in w1:
            wd1.append(word1.count(i))
            wd2.append(word2.count(i))
            
        if sorted(wd1) != sorted(wd2): return False
        

        return True