# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def midnode(self,head: Optional[ListNode]) -> None:
        slow=fast=head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        return slow
    def reverse(self,head: Optional[ListNode]) -> None:
        pre,cur=None,head
        while cur:
            ne=cur.next
            cur.next=pre
            pre=cur
            cur=ne
        return pre
            
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        mid=self.midnode(head)
        head2=self.reverse(mid)
        while head2.next:
            ne=head.next
            ne2=head2.next
            head.next=head2
            head2.next=ne
            head=ne
            head2=ne2
        