from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class LinkedListCycle:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        ahead: Optional[ListNode] = head
        behind: Optional[ListNode] = head

        while ahead != None and ahead.next != None:
            ahead = ahead.next.next
            behind = behind.next

            if ahead == behind:
                return True

        return False


    # Solution
    ##
    # Floyd's Tortoise and Hare Algorithm
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False

        slow = head
        fast = head.next

        while slow != fast:
            if not fast or not fast.next:
                return False

            slow = slow.next
            fast = fast.next.next

        return True
