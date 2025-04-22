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

  public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode current = head;

    while (current != null) {
      ListNode next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }

    return prev;
  }


  // Solution
  // Solution 1: iterative solution
  public ListNode solution1(ListNode head) {
    ListNode newHead = null;
    while (head != null) {
      ListNode next = head.next;
      head.next = newHead;
      newHead = head;
      head = next;
    }
    return newHead;
  }

  // Solution 2: recursive solution
  private ListNode reverseListInt(ListNode head, ListNode newHead) {
    if (head == null) {
      return newHead;
    }
    ListNode next = head.next;
    head.next = newHead;
    return reverseListInt(next, head);
  }

  public ListNode solution2(ListNode head) {
    /* recursive solution */
    return reverseListInt(head, null);
  }
}
