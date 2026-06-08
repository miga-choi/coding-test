from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class RemoveLinkedListElements:
    """
    # Dummy Node
    #
    # Complexities:
    #   N - Number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head == None:
            return None

        newHead = ListNode(0)
        newHead.next = head
        currentHead = newHead

        while currentHead.next != None:
            if currentHead.next.val == val:
                currentHead.next = currentHead.next.next
            else:
                currentHead = currentHead.next

        return newHead.next


    # Solution
    """
    # Solution 1
    # 
    # Dummy Node
    #
    # Complexities:
    #   N - Number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        
        curr = dummy
        
        while curr and curr.next:
            if curr.next.val == val:
                curr.next = curr.next.next
            else:
                curr = curr.next
                
        return dummy.next

    """
    # Solution 2
    # 
    # Recursive
    #
    # Complexities:
    #   N - Number of nodes in `head`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head:
            return None
            
        head.next = self.solution2(head.next, val)
        
        return head.next if head.val == val else head
