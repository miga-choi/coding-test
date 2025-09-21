from typing import Optional, List

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class ReverseLinkedList:
    ##
    # Iteration
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    #
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head

        stack: List = []

        while head != None:
            stack.append(head)
            head = head.next

        new_head: Optional[ListNode] = stack.pop()
        curr_head: Optional[ListNode] = new_head

        while len(stack) > 0:
            curr_head.next = stack.pop()
            curr_head = curr_head.next

        curr_head.next = None

        return new_head


    # Solution
    ##
    # Solution 1
    #
    # Iteration
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution1(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        current = head

        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        return prev

    ##
    # Solution 2
    #
    # Recursion
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    #
    def solution2(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        new_head = self.solution2(head.next)

        head.next.next = head
        head.next = None

        return new_head
