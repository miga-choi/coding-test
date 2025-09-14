class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class RemoveDuplicatesFromSortedList {
  /**
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  ListNode? deleteDuplicates(ListNode? head) {
    ListNode? currHead = head;

    while (currHead != null) {
      if (currHead.next != null && currHead.next!.val == currHead.val) {
        currHead.next = currHead.next!.next;
      } else {
        currHead = currHead.next;
      }
    }

    return head;
  }


  // Solution
  /**
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  ListNode? solution(ListNode? head) {
    if (head == null || head.next == null) {
      return head;
    }

    ListNode? current = head;

    while (current != null && current.next != null) {
      if (current.val == current.next!.val) {
        current.next = current.next!.next;
      } else {
        current = current.next;
      }
    }

    return head;
  }
}
