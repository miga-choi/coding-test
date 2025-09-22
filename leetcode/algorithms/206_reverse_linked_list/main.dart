class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class ReverseLinkedList {
  /**
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  ListNode? reverseList(ListNode? head) {
    if (head == null || head.next == null) {
      return head;
    }

    List<ListNode?> stack = List<ListNode>.empty(growable: true);

    while (head != null) {
      stack.add(head);
      head = head.next;
    }

    ListNode? newHead = stack.removeLast();
    ListNode? currHead = newHead;

    while (stack.isNotEmpty) {
      currHead?.next = stack.removeLast();
      currHead = currHead?.next;
    }

    currHead?.next = null;

    return newHead;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  ListNode? solution1(ListNode? head) {
    ListNode? prev = null;
    ListNode? current = head;
    ListNode? nextTemp;

    while (current != null) {
      nextTemp = current.next;
      current.next = prev;
      prev = current;
      current = nextTemp;
    }

    return prev;
  }

  /**
   * Solution 2
   * 
   * Recursion
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  ListNode? solution2(ListNode? head) {
    if (head == null || head.next == null) {
      return head;
    }

    ListNode? p = solution2(head.next);

    head.next!.next = head;
    head.next = null;

    return p;
  }
}
