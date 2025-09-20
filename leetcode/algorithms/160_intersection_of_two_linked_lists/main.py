from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class IntersectionOfTwoLinkedLists:
    ##
    # Two-Pointer
    # - Time Complexity: O(M + N)
    # - Space Complexity: O(1)
    #
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        dummyA: Optional[ListNode] = headA
        dummyB: Optional[ListNode] = headB

        while dummyA != dummyB:
            dummyA = headB if dummyA == None else dummyA.next
            dummyB = headA if dummyB == None else dummyB.next

        return dummyA


    # Solution
    ##
    # Two-Pointer
    # - Time Complexity: O(M + N)
    # - Space Complexity: O(1)
    #
    def solution(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        pA, pB = headA, headB

        while pA != pB:
            pA = pA.next if pA else headB
            pB = pB.next if pB else headA

        return pA
