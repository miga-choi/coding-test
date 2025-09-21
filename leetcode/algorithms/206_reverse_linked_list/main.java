import java.util.Stack;

class ReverseLinkedList {
  class ListNode {
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
   * - Space Complexity: O(N)
   */
  public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    Stack<ListNode> stack = new Stack<>();

    while (head != null) {
      stack.push(head);
      head = head.next;
    }

    ListNode newHead = stack.pop();
    ListNode currHead = newHead;

    while (!stack.empty()) {
      currHead.next = stack.pop();
      currHead = currHead.next;
    }

    currHead.next = null;

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
  public ListNode solution1(ListNode head) {
    ListNode prev = null;
    ListNode current = head;

    while (current != null) {
      ListNode nextTemp = current.next;
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
   * - Space Complexity: O(N)
   */
  public ListNode solution2(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    ListNode newHead = solution2(head.next);

    head.next.next = head;
    head.next = null;

    return newHead;
  }
}
