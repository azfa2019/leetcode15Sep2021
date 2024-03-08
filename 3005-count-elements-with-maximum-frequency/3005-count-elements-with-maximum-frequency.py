class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        hash={}
        for num in nums:
            if num in hash:
                hash[num]+=1
            else:
                hash[num]=1
        freq=0
        for k,v in hash.items():
            if freq<v:
                freq=v
        res=0
        for k,v in hash.items():
            if v==freq:
                res+=v
        return res