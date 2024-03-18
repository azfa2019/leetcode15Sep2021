class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l=-1
        r=len(nums)-1
        while l+1<r:
            mid=(l+r)//2
            if nums[mid]>nums[mid+1]:
                r=mid
            else:
                l=mid
        return r