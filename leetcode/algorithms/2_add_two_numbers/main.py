from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class AddTwoNumbers:
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
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(0)
        tail = dummyHead
        carry = 0

        while l1 is not None or l2 is not None or carry != 0:
            digit1 = l1.val if l1 is not None else 0
            digit2 = l2.val if l2 is not None else 0

            sum = digit1 + digit2 + carry
            digit = sum % 10
            carry = sum // 10

            newNode = ListNode(digit)
            tail.next = newNode
            tail = tail.next

            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None

        result = dummyHead.next
        dummyHead.next = None

        return result
