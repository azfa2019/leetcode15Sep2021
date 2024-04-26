# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        def dfs(root: Optional[TreeNode],d:int) -> None:
            if root is None:
                return
            if len(ans)==d:
                ans.append(root.val)
            dfs(root.right,d+1)
            dfs(root.left,d+1)
        dfs(root,0)
        return ans