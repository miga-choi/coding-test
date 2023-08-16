from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        obverse = []
        reverse = []

        newHead: ListNode = head

        while newHead:
            obverse.append(newHead.val)
            newHead = newHead.next

        prev: ListNode = None
        current = head

        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next

        while prev:
            reverse.append(prev.val)
            prev = prev.next

        for i in range(len(obverse)):
            if obverse[i] != reverse[i]:
                return False

        return True


    # Best Solution
    def bestSolution(self, head: ListNode) -> bool:
        slow, fast, prev = head, head, None

        while fast and fast.next:
            slow, fast = slow.next, fast.next.next

        prev, slow, prev.next = slow, slow.next, None

        while slow:
            slow.next, prev, slow = prev, slow, slow.next

        fast, slow = head, prev

        while slow:
            if fast.val != slow.val:
                return False
            fast, slow = fast.next, slow.next

        return True
