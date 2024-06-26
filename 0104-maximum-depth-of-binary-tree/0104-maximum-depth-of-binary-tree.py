# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        ans=0
        def dfs(root,cnt):
            if root is None:
                return
            cnt+=1
            nonlocal ans
            ans=max(ans,cnt)
            dfs(root.left,cnt)
            dfs(root.right,cnt)
        dfs(root,0)
        return ans