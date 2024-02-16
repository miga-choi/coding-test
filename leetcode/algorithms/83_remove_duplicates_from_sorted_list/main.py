from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class RemoveDuplicatesFromSortedList:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result = head
        while result:
            if result.next and result.val == result.next.val:
                result.next = result.next.next
            else:
                result = result.next
        return head


    # Best Solution
    # Best Solution 1: iterative
    def bestSolution1(self, head: ListNode) -> ListNode:
        cur = head
        while cur:
            while cur.next and cur.next.val == cur.val:
                cur.next = cur.next.next  # skip duplicated node
            cur = cur.next  # not duplicate of current node, move to next node
        return head

    # Best Solution 2:
    def bestSolution2(self, head: ListNode) -> ListNode:
        temp = head
        while temp and temp.next:
            if temp.next.val == temp.val:
                temp.next = temp.next.next
                continue
            temp = temp.next
        return head
