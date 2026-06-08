class RemoveLinkedListElements {
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
   * Dummy Node
   *
   * Complexities:
   *   N - Number of nodes in `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public ListNode removeElements(ListNode head, int val) {
    if (head == null) {
      return null;
    }

    ListNode returnHead = new ListNode();
    returnHead.next = head;

    ListNode currentHead = head;
    ListNode prevHead = returnHead;

    while (currentHead != null) {
      if (currentHead.val == val) {
        prevHead.next = currentHead.next;
      } else {
        prevHead = prevHead.next;
      }
      currentHead = currentHead.next;
    }

    return returnHead.next;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Dummy Node
   *
   * Complexities:
   *   N - Number of nodes in `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public ListNode solution1(ListNode head, int val) {
    ListNode dummy = new ListNode(-1);
    dummy.next = head;

    ListNode curr = dummy;

    while (curr.next != null) {
      if (curr.next.val == val) {
        curr.next = curr.next.next;
      } else {
        curr = curr.next;
      }
    }

    return dummy.next;
  }

  /**
   * Solution 2
   * 
   * Recursion
   *
   * Complexities:
   *   N - Number of nodes in `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public ListNode solution2(ListNode head, int val) {
    if (head == null) {
      return null;
    }

    head.next = solution2(head.next, val);

    return head.val == val ? head.next : head;
  }
}
