from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class PalindromeLinkedList:
    """
    # Complexities:
    #   N - The number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        obverse = []
        reverse = []

        newHead: ListNode = head

        while newHead:
            obverse.append(newHead.val)
            newHead = newHead.next

        prev: ListNode = None
        current = head

        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next

        while prev:
            reverse.append(prev.val)
            prev = prev.next

        for i in range(len(obverse)):
            if obverse[i] != reverse[i]:
                return False

        return True


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   N - The number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, head: ListNode) -> bool:
        vals = []
        curr = head

        while curr:
            vals.append(curr.val)
            curr = curr.next

        return vals == vals[::-1]

    """
    # Solution 2
    #
    # Complexities:
    #   N - The number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
            
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        prev = None
        curr = slow
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
            
        p1 = head
        p2 = prev
        is_palindrome = True
        
        while p2:
            if p1.val != p2.val:
                is_palindrome = False
                break
            p1 = p1.next
            p2 = p2.next
            
        curr = prev
        prev_restore = None
        while curr:
            next_node = curr.next
            curr.next = prev_restore
            prev_restore = curr
            curr = next_node
            
        return is_palindrome
