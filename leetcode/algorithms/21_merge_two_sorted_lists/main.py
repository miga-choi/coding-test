from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class MergeTwoSortedLists:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        result: ListNode = ListNode()
        currentNode: ListNode = result

        while list1 or list2:
            if list1 and list2:
                if list1.val > list2.val:
                    currentNode.next = list2
                    list2 = list2.next
                else:
                    currentNode.next = list1
                    list1 = list1.next
            elif list1:
                currentNode.next = list1
                list1 = list1.next
            else:
                currentNode.next = list2
                list2 = list2.next
            currentNode = currentNode.next

        return result.next


    # Solution
    # Solution 1:
    def bestSolution1(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        cur = dummy = ListNode()

        while list1 and list2:
            if list1.val < list2.val:
                cur.next = list1
                list1, cur = list1.next, list1
            else:
                cur.next = list2
                list2, cur = list2.next, list2

        if list1 or list2:
            cur.next = list1 if list1 else list2

        return dummy.next

    # Solution 2: iteratively
    def solution2(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = cur = ListNode(0)

        while list1 and list2:
            if list1.val < list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next
            cur = cur.next

        cur.next = list1 or list2

        return dummy.next

    # Solution 3: recursively
    def solution3(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 or not list2:
            return list1 or list2
            
        if list1.val < list2.val:
            list1.next = self.solution3(list1.next, list2)
            return list1
        else:
            list2.next = self.solution3(list1, list2.next)
            return list2

    # Solution 4: in-place, iteratively
    def solution4(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if None in (list1, list2):
            return list1 or list2

        dummy = cur = ListNode(0)
        dummy.next = list1

        while list1 and list2:
            if list1.val < list2.val:
                list1 = list1.next
            else:
                nxt = cur.next
                cur.next = list2
                tmp = list2.next
                list2.next = nxt
                list2 = tmp

            cur = cur.next

        cur.next = list1 or list2

        return dummy.next
