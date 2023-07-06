class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l=s=0
        n=len(nums)
        ans=n+1
        for r,x in enumerate(nums):
            s+=x
            while s>=target:
                ans=min(ans,r-l+1)
                s-=nums[l]
                l+=1
        return ans if ans<=n else 0