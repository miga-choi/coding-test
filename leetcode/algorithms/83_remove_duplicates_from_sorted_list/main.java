class RemoveDuplicatesFromSortedList {
  public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
      this.val = val;
    }

    ListNode(int val, ListNode next) {
      this.val = val;
      this.next = next;
    }
  }

  /**
   * Iteration
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  public ListNode deleteDuplicates(ListNode head) {
    ListNode currHead = head;

    while (currHead != null) {
      if (currHead.next != null && currHead.val == currHead.next.val) {
        currHead.next = currHead.next.next;
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
  public ListNode solution(ListNode head) {
    if (head == null) {
      return null;
    }

    ListNode current = head;

    while (current != null && current.next != null) {
      if (current.val == current.next.val) {
        current.next = current.next.next;
      } else {
        current = current.next;
      }
    }

    return head;
  }
}
