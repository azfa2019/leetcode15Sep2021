class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r=-1,len(nums)-1
        while l+1<r:
            mid=(l+r)//2
            if nums[mid]<nums[-1]:
                r=mid
            else:
                l=mid
        return nums[r]