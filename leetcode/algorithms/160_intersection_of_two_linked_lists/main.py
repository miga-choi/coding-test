from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class IntersectionOfTwoLinkedLists:
    """
    # Two-Pointer
    #
    # Complexities:
    #   N - Number of Nodes in `headA`
    #   M - Number of Nodes in `headB`
    #   - Time Complexity: O(M + N)
    #   - Space Complexity: O(1)
    """
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if not headA or not headB:
            return None

        ptrA, ptrB = headA, headB

        while ptrA != ptrB:
            ptrA = ptrA.next if ptrA else headB
            ptrB = ptrB.next if ptrB else headA

        return ptrA


    # Solution
    """
    # Solution 1
    #
    # Two-Pointer
    #
    # Complexities:
    #   N - Number of Nodes in `headA`
    #   M - Number of Nodes in `headB`
    #   - Time Complexity: O(M + N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if not headA or not headB:
            return None

        pA, pB = headA, headB

        while pA != pB:
            pA = pA.next if pA else headB
            pB = pB.next if pB else headA

        return pA

    """
    # Solution 2
    #
    # Length Difference
    #
    # Complexities:
    #   N - Number of Nodes in `headA`
    #   M - Number of Nodes in `headB`
    #   - Time Complexity: O(M + N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        def get_length(node: ListNode) -> int:
            length = 0
            while node:
                length += 1
                node = node.next
            return length

        lenA = get_length(headA)
        lenB = get_length(headB)

        pA, pB = headA, headB

        if lenA > lenB:
            for _ in range(lenA - lenB):
                pA = pA.next
        else:
            for _ in range(lenB - lenA):
                pB = pB.next

        while pA and pB:
            if pA == pB:
                return pA
            pA = pA.next
            pB = pB.next

        return None
