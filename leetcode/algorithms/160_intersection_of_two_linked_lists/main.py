from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class IntersectionOfTwoLinkedLists:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        a = headA
        b = headB
        while a is not b:
            if a is None:
                a = headB
            else:
                a = a.next
            if b is None:
                b = headA
            else:
                b = b.next
        return a


    # Solution
    def solution(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        stackA = ["A"]
        stackB = ["B"]

        while headA or headB:
            if headA:
                stackA.append(headA)
                headA = headA.next

            if headB:
                stackB.append(headB)
                headB = headB.next

        prev = None
        while stackA and stackB:
            nodeA = stackA.pop(-1)
            nodeB = stackB.pop(-1)

            if nodeA != nodeB:
                return prev

            prev = nodeA
