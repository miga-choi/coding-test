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
  // Solution 1
  public ListNode solution1(ListNode head, int val) {
    if (head == null) {
      return null;
    }
    head.next = removeElements(head.next, val);
    return head.val == val ? head.next : head;
  }

  // solution 2
  public ListNode solution2(ListNode head, int val) {
    ListNode fakeHead = new ListNode(-1);
    fakeHead.next = head;
    ListNode curr = head, prev = fakeHead;
    while (curr != null) {
      if (curr.val == val) {
        prev.next = curr.next;
      } else {
        prev = prev.next;
      }
      curr = curr.next;
    }
    return fakeHead.next;
  }
}
