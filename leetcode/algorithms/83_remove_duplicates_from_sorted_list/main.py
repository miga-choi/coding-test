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


    # Solution
    # Solution 1: iterative
    def solution1(self, head: ListNode) -> ListNode:
        cur = head

        while cur:
            while cur.next and cur.next.val == cur.val:
                # skip duplicated node
                cur.next = cur.next.next

            # not duplicate of current node, move to next node
            cur = cur.next

        return head

    # Solution 2:
    def solution2(self, head: ListNode) -> ListNode:
        temp = head
        while temp and temp.next:
            if temp.next.val == temp.val:
                temp.next = temp.next.next
                continue
            temp = temp.next
        return head
