from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class RemoveDuplicatesFromSortedList:
    ##
    # Iteration
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr_head: Optional[ListNode] = head

        while curr_head:
            if curr_head.next and curr_head.val == curr_head.next.val:
                curr_head.next = curr_head.next.next
            else:
                curr_head = curr_head.next

        return head


    # Solution
    ##
    # Solution 1
    #
    # Iteration
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution1(self, head: ListNode) -> ListNode:
        if not head:
            return None

        current = head

        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next

        return head

    ##
    # Solution 2
    #
    # Recursion
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    #
    def solution2(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        head.next = self.solution2(head.next)

        if head.val == head.next.val:
            return head.next
        else:
            return head
