class Solution:
    def findLeastNumOfUniqueInts(self, a: list[int], k: int) -> int:
        return (c := Counter(a)) and len(set(sorted(a, key=lambda x: (c[x], x))[k:]))