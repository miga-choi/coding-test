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
   *
   * Complexities:
   *   N - Size of `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
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
   * Solution 1
   * 
   * Iteration
   *
   * Complexities:
   *   N - Size of `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public ListNode solution1(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    ListNode curr = head;

    while (curr != null && curr.next != null) {
      if (curr.val == curr.next.val) {
        curr.next = curr.next.next;
      } else {
        curr = curr.next;
      }
    }

    return head;
  }

  /**
   * Solution 2
   * 
   * Recursion
   *
   * Complexities:
   *   N - Size of `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public ListNode solution2(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    head.next = solution2(head.next);

    return head.val == head.next.val ? head.next : head;
  }
}
