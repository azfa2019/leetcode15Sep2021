def lowerbound(nums:List[int],target:int)->int:
    l=0
    r=len(nums)
    while l<r:
        mid=(l+r)//2
        if nums[mid]>=target:
            r=mid
        else:
            l=mid+1
    return l
class Solution:    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start=lowerbound(nums,target)
        if start==len(nums) or nums[start]!=target:
            return [-1,-1]
        end=lowerbound(nums,target+1)-1
        return [start,end]