from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class LinkedListCycle:
    """
    # Floyd's Tortoise and Hare Algorithm (Two Pointers)
    #
    # Complexities:
    #   N - Number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        ahead: Optional[ListNode] = head
        behind: Optional[ListNode] = head

        while ahead != None and ahead.next != None:
            ahead = ahead.next.next
            behind = behind.next

            if ahead == behind:
                return True

        return False


    # Solution
    """
    # Solution 1
    #
    # HashSet
    #
    # Complexities:
    #   N - Number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, head: ListNode) -> bool:
        visited = set()
        curr = head
        
        while curr:
            if curr in visited:
                return True
            visited.add(curr)
            curr = curr.next
            
        return False

    """
    # Solution 2
    #
    # Floyd's Tortoise and Hare Algorithm (Two Pointers)
    #
    # Complexities:
    #   N - Number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
            
        slow = head
        fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:
                return True
                
        return False
