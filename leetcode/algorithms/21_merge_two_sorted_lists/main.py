from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class MergeTwoSortedLists:
    """
    # Iterative + Dummy Node
    #
    # Complexities:
    #   N - Length of `list1`
    #   M - Length of `list2`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(1)
    """
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy: Optional[ListNode] = ListNode()
        curr_head: Optional[ListNode] = dummy

        while list1 != None and list2 != None:
            if list1.val > list2.val:
                curr_head.next = list2
                list2 = list2.next
            else:
                curr_head.next = list1
                list1 = list1.next
            currentNode = currentNode.next

        curr_head.next = list2 if list1 == None else list1

        return dummy.next


    # Solution
    """
    # Solution 1
    #
    # Iterative + Dummy Node
    #
    # Complexities:
    #   N - Length of `list1`
    #   M - Length of `list2`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(1)
    """
    def solution1(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)
        current = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next

        if list1:
            current.next = list1
        elif list2:
            current.next = list2

        return dummy.next

    """
    # Solution 2
    #
    # Recursive
    #
    # Complexities:
    #   N - Length of `list1`
    #   M - Length of `list2`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(N + M)
    """
    def solution2(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1

        if list1.val <= list2.val:
            list1.next = self.solution2(list1.next, list2)
            return list1
        else:
            list2.next = self.solution2(list1, list2.next)
            return list2
