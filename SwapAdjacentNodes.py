# Given a linked list, swap every two adjacent nodes and return its head. 
# You must solve the problem without modifying the values in the list's nodes 
# (i.e., only nodes themselves may be changed.)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        dummy.next = head
        prev = dummy
        curr = head

        while(curr and curr.next):
            prev.next = curr.next
            curr.next = prev.next.next
            prev.next.next = curr

            prev = curr
            curr = curr.next

        return dummy.next