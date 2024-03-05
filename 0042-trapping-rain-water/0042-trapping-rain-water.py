class Solution:
    def trap(self, height: List[int]) -> int:
      n=len(height)
      l=0
      r=n-1
      premax=sufmax=ans=0
      while l<r:
         premax=max(premax,height[l])
         sufmax=max(sufmax,height[r])
         if premax<sufmax:
            ans+=premax-height[l]
            l+=1
         else:
            ans+=sufmax-height[r]
            r-=1
      return ans