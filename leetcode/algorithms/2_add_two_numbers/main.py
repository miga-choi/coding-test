from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class AddTwoNumbers:
    """
    # Complexities:
    #   M - l1 length
    #   N - l2 length
    #   - Time Complexity: O(Max(M, N))
    #   - Space Complexity: O(Max(M, N))
    """
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry: int = 0

        result: Optional[ListNode] = ListNode()
        head: Optional[ListNode] = result

        while l1 != None or l2 != None or carry > 0:
            sum: int = carry
            carry = 0

            if l1 != None:
                sum += l1.val
                l1 = l1.next

            if l2 != None:
                sum += l2.val
                l2 = l2.next

            if sum > 9:
                sum -= 10
                carry = 1

            head.next = ListNode(sum)
            head = head.next

        return result.next


    # Solution
    """
    # Complexities:
    #   M - l1 length
    #   N - l2 length
    #   - Time Complexity: O(Max(M, N))
    #   - Space Complexity: O(Max(M, N))
    """
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        current = dummy
        carry = 0

        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            total = val1 + val2 + carry

            carry = total // 10
            digit = total % 10

            current.next = ListNode(digit)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy.next
