from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        stack = []
        while head != None:
            if head in stack:
                return True
            stack.append(head)
            head = head.next
        return False


    # Best Solution
    # Dictionary/Hash table
    def bestSolution1(self, head: ListNode) -> bool:
        dictionary = {}
        while head:
            if head in dictionary:
                return True
            else:
                dictionary[head] = True
            head = head.next
        return False

    # Two pointers
    def bestSolution2(self, head: ListNode) -> bool:
        if not head:
            return False
        slow = head
        fast = head.next
        while slow != fast:
            if not fast or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
